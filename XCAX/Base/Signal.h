#pragma once

#include <boost\signals2.hpp>
#include <any>
#include <memory>
#include <thread>

using SignalConnectionHandle = boost::signals2::connection;

class ISignalThreadHelper {
	public:
		virtual ~ISignalThreadHelper() = default;

		virtual std::any GetCurrentThreadContext() = 0;

		virtual void ExecInThread(const std::any& context, const std::function<void()>& fn) = 0;

};

ISignalThreadHelper* GetGlobalSignalThreadHelper();
void SetGlobalSignalThreadHelper(std::unique_ptr<ISignalThreadHelper> helper);

template<typename... Args>
class Signal
{
public:
    Signal() = default;
    Signal(const Signal&) = delete;
    Signal& operator=(Signal const& other) = delete;
    Signal(Signal && other) noexcept = default;
    Signal& operator=(Signal && other) noexcept = default;

    void send(Args... p) const
    {
        signal(p...);
    }

    SignalConnectionHandle connectSlot(const std::function<void(Args...)>&fnSlot)
    {
        if (GetGlobalSignalThreadHelper()) {
            auto threadContext = GetGlobalSignalThreadHelper()->GetCurrentThreadContext();
            auto connectThreadId = std::this_thread::get_id();
            auto fnWrap = [=](Args... args) {
                auto emitThreadId = std::this_thread::get_id();
                if (emitThreadId == connectThreadId)
                    fnSlot(args...);
                else
                    GetGlobalSignalThreadHelper()->execInThread(threadContext, [=] { fnSlot(args...); });
            };
            return signal.connect(fnWrap);
        }
        else {
            return signal.connect(fnSlot);
        }
    }

    template<typename FunctionSlot, typename... FunctionSlotArgs, 
        typename = std::enable_if_t<std::disjunction_v<std::negation<std::is_convertible<FunctionSlot,
        std::function<void(Args...)>>>, std::integral_constant<bool, sizeof...(FunctionSlotArgs)>>>>
        SignalConnectionHandle connectSlot(FunctionSlot && fnSlot, FunctionSlotArgs&&... args)
    {
        std::function<void(Args...)> bound = boost::bind(std::forward<FunctionSlot>(fnSlot), 
            std::forward<FunctionSlotArgs>(args)...);
        return connectSlot(bound);
    }

private:
    boost::signals2::signal<void(Args...)> signal;
};

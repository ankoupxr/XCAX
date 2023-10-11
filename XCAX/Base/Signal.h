#pragma once

#include <boost\signals2.hpp>
#include <any>
#include <memory>
#include <thread>


class ConnectionManager {
	public:
		ConnectionManager() = default;
		ConnectionManager(const ConnectionManager&) = delete;
        ConnectionManager& operator=(const ConnectionManager&) = delete;

        ~ConnectionManager() {
            disconnectAll();
        }

        template<typename Func>
        void connect(const Func& func) {
            m_connections.push_back(m_signal.connect(func));
        }

        void disconnectAll() {
            for (auto& connection : m_connections) {
                connection.disconnect();
            }
            m_connections.clear();
        }

private:
    boost::signals2::signal<void()> m_signal;
    std::vector<boost::signals2::connection> m_connections;
};
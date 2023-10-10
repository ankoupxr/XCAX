#include "Signal.h"

std::unique_ptr<ISignalThreadHelper> globalHelper;

void SetGlobalSignalThreadHelper(std::unique_ptr<ISignalThreadHelper> helper)
{
	globalHelper = std::move(helper);
}

ISignalThreadHelper* GetGlobalSignalThreadHelper()
{
	return globalHelper.get();
}

#pragma once
#include <Command.h>


class ChamferCommand : public Command {
	Q_OBJECT
public:
	ChamferCommand(AppPtr app);
	void Execute() override;
	static constexpr std::string_view Name = "chamfer";
};

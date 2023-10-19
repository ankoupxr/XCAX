#pragma once
#include <Command.h>


class CreateCubeCommand : public Command {
	Q_OBJECT
public:
	CreateCubeCommand(AppPtr app);
	void Execute() override;
	static constexpr std::string_view Name = "new-cube";
};

class Create
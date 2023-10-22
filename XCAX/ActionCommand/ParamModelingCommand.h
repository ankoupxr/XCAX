#pragma once
#include <Command.h>
#include "../cube_widget.h"


class CreateCubeCommand : public Command {
	Q_OBJECT
public:
	CreateCubeCommand(AppPtr app);
	void Execute() override;
	static constexpr std::string_view Name = "new-cube";
private:
	cube_widget* cubeDialog;
};

#pragma once
#include <Command.h>

class NewFileCommand : public Command {
	public:
		NewFileCommand(AppPtr app);
		void Execute() override;
		static constexpr std::string_view Name = "newdoc";
};

//class OpenFileCommand : Command
//{
//public:
//	OpenFileCommand();
//	void Execute() override;
//	static constexpr std::string_view Name = "´ò¿ª";
//
//private:
//
//};

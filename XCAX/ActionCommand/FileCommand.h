#pragma once
#include <Command.h>

class NewFileCommand : public Command {
	Q_OBJECT
	public:
		NewFileCommand(AppPtr app);
		void Execute() override;
		static constexpr std::string_view Name = "newdoc";
	signals:
		void sendNewFileSignal(const DocPtr& doc);
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


class ImportStepCommand : public Command {
	Q_OBJECT
	public:
		ImportStepCommand(AppPtr app);
		void Execute() override;
		static constexpr std::string_view Name = "importstep";
};


class ImportObjCommand : public Command {
	Q_OBJECT
	public:
		ImportObjCommand(AppPtr app);
		//void Execute() override;
		static constexpr std::string_view Name = "importobj";
};
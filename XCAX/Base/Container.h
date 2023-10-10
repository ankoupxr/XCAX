#pragma once
#include <Command.h>
#include <unordered_map>


class AppContext : public QObject {
	Q_OBJECT
public:
	AppContext(QObject* parent = nullptr);

private:

};

class CommandContainer
{
public:
	CommandContainer();

	void AddCommand(std::string_view name,Command* cmd);
	template<typename CmdType> void AddNamedCommand();

	Command* CommandContainer::FindCommand(std::string_view name) const;

	QAction* CommandContainer::FindCommandAction(std::string_view name) const;

	void SetApp(AppPtr app) { m_app = app; }

private:
	std::unordered_map<std::string_view, Command*> m_commandMap;
	AppPtr m_app = nullptr;
};



template<typename CmdType>
void CommandContainer::AddNamedCommand()
{
	auto cmd = new CmdType(m_app);
	this->AddCommand(CmdType::Name, cmd);
}
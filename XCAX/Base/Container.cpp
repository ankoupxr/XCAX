#include <Container.h>

CommandContainer::CommandContainer()
{

}

void CommandContainer::AddCommand(std::string_view name, Command* cmd)
{
	auto [it, ok] = m_commandMap.insert({ name, cmd });
}

Command* CommandContainer::FindCommand(std::string_view name) const
{
    auto it = m_commandMap.find(name);
    return it != m_commandMap.cend() ? it->second : nullptr;
}

QAction* CommandContainer::FindCommandAction(std::string_view name) const
{
    auto cmd = this->FindCommand(name);
    return cmd ? cmd->Action() : nullptr;
}
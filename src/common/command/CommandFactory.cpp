/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandFactory.cpp
*/

#include "CommandFactory.hpp"

babel::common::CommandFactory::CommandFactory() :
	_commands({{babel::common::CommandName::CMD_ERROR,
			   &babel::common::CommandFactory::createCommand
				   <CommandError>},
		   {babel::common::CommandName::OK,
			   &babel::common::CommandFactory::createCommand
				   <CommandOk>},
		   {babel::common::CommandName::LOGIN,
			   &babel::common::CommandFactory::createCommand
				   <CommandLogin>},
		   {babel::common::CommandName::LOGIN_OK,
			   &babel::common::CommandFactory::createCommand
				   <CommandLoginOk>},
		   {babel::common::CommandName::LOGOUT,
			   &babel::common::CommandFactory::createCommand
				   <CommandLogout>},
		   {babel::common::CommandName::DELETE,
			   &babel::common::CommandFactory::createCommand
				   <CommandDelete>},
		   {babel::common::CommandName::USER,
			   &babel::common::CommandFactory::createCommand
				   <CommandUser>},
		   {babel::common::CommandName::USER_STATE,
			   &babel::common::CommandFactory::createCommand
				   <CommandUserState>},
		   {babel::common::CommandName::CALL,
			   &babel::common::CommandFactory::createCommand
				   <CommandCall>},
		   {babel::common::CommandName::CALL_ANSWER,
			   &babel::common::CommandFactory::createCommand
				   <CommandCallAnswer>},
		   {babel::common::CommandName::CALL_END,
			   &babel::common::CommandFactory::createCommand
				   <CommandCallEnd>},
		   {babel::common::CommandName::ADD_CONTACT,
			   &babel::common::CommandFactory::createCommand
				   <CommandAddContact>},
		   {babel::common::CommandName::MESSAGE,
			   &babel::common::CommandFactory::createCommand
				   <CommandMessage>}
		  })
{}

std::unique_ptr<babel::common::ACommand>
babel::common::CommandFactory::deserialize(babel::common::DataPacket packet)
{
	if (_commands.find(packet.getCommandId()) != _commands.end())
		return (this->*_commands[packet.getCommandId()])
			(packet.getArgs());
	throw CommandException(UNDEFINED, "Unknow command");
}

template<class T>
std::unique_ptr<babel::common::ACommand>
babel::common::CommandFactory::createCommand(
	std::vector<std::string> args)
{
	return std::make_unique<T>(args);
}
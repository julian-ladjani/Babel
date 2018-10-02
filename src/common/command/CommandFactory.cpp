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
		   {babel::common::CommandName::CMD_OK,
			   &babel::common::CommandFactory::createCommand
				   <CommandOk>},
		   {babel::common::CommandName::CMD_LOGIN,
			   &babel::common::CommandFactory::createCommand
				   <CommandLogin>},
		   {babel::common::CommandName::CMD_LOGIN_OK,
			   &babel::common::CommandFactory::createCommand
				   <CommandLoginOk>},
		   {babel::common::CommandName::CMD_LOGOUT,
			   &babel::common::CommandFactory::createCommand
				   <CommandLogout>},
		   {babel::common::CommandName::CMD_DELETE,
			   &babel::common::CommandFactory::createCommand
				   <CommandDelete>},
		   {babel::common::CommandName::CMD_USER,
			   &babel::common::CommandFactory::createCommand
				   <CommandUser>},
		   {babel::common::CommandName::CMD_USER_STATE,
			   &babel::common::CommandFactory::createCommand
				   <CommandUserState>},
		   {babel::common::CommandName::CMD_CALL,
			   &babel::common::CommandFactory::createCommand
				   <CommandCall>},
		   {babel::common::CommandName::CMD_CALL_ANSWER,
			   &babel::common::CommandFactory::createCommand
				   <CommandCallAnswer>},
		   {babel::common::CommandName::CMD_CALL_END,
			   &babel::common::CommandFactory::createCommand
				   <CommandCallEnd>},
		   {babel::common::CommandName::CMD_ADD_CONTACT,
			   &babel::common::CommandFactory::createCommand
				   <CommandAddContact>},
		   {babel::common::CommandName::CMD_MESSAGE,
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
	throw CommandException(CMD_UNDEFINED, "Unknow command");
}

template<class T>
std::unique_ptr<babel::common::ACommand>
babel::common::CommandFactory::createCommand(
	std::vector<std::string> args)
{
	return std::make_unique<T>(args);
}
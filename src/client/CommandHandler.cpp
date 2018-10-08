/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.cpp
*/

#include <src/common/command/CommandLogout.hpp>
#include <src/common/command/CommandDelete.hpp>
#include <src/common/command/CommandFactory.hpp>
#include "CommandHandler.hpp"

babel::client::CommandHandler::CommandHandler(babel::client::ClientInfo &info) :
	_infos(info),
	_commandHandlers({{babel::common::CommandName::CMD_LOGIN_OK,
				  &CommandHandler
				  ::commandLoginOkHandler},
			  {babel::common::CommandName::CMD_DELETE,
				  &CommandHandler
				  ::commandDeleteHandler},
			  {babel::common::CommandName::CMD_USER,
				  &CommandHandler
				  ::commandUserHandler},
			  {babel::common::CommandName::CMD_CALL,
				  &CommandHandler
				  ::commandCallHandler},
			  {babel::common::CommandName::CMD_CALL_ANSWER,
				  &CommandHandler
				  ::commandCallAnswerHandler},
			  {babel::common::CommandName::CMD_CALL_END,
				  &CommandHandler
				  ::commandCallEndHandler},
			  {babel::common::CommandName::CMD_CONTACT,
				  &CommandHandler
				  ::commandContactHandler},
			  {babel::common::CommandName::CMD_MESSAGE,
				  &CommandHandler
				  ::commandMessageHandler},
			 })
{
	connect(&_infos.getSocket(), &QtTcpSocket::newPacket,
		this, &CommandHandler::tryToHandle);
}

void babel::client::CommandHandler::tryToHandle()
{
	common::CommandFactory cmdFactory;
	auto dataPacket = _infos.getSocket().receive();
	while (dataPacket.getCommandId() != common::CMD_UNDEFINED) {
		auto cmd = cmdFactory.deserialize(dataPacket);
		handleCommand(cmd);
		dataPacket = _infos.getSocket().receive();
	}
}

bool
babel::client::CommandHandler::handleCommand(
	std::unique_ptr<babel::common::ACommand> &command)
{
	if (_commandHandlers.find(command->getCommandId())
	    != _commandHandlers.end())
		return (this->*_commandHandlers[command->getCommandId()])
			(command);
	return false;
}

bool babel::client::CommandHandler::commandLoginOkHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	printf("LOGIN OK\n");
	emit changePage("main");
	return true;
	(void)command;
}

bool babel::client::CommandHandler::commandDeleteHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	for(int i = 0; _infos.getContacts().size(); i++)
		if (_infos.getContacts()[i].getId()
		    == (unsigned short)stoi(command->getArgs()[0]))
			_infos.removeContact(_infos.getContacts()[i]);
	return true;
}

bool babel::client::CommandHandler::commandUserHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	common::CommandUser &cmd = (common::CommandUser &) *command;
	_infos.addContact({cmd.getUsername(), cmd.getUserId(),
			cmd.isConnected()});
	emit newContact();
	return true;
}

bool babel::client::CommandHandler::commandCallHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	//_infos.getSocket().send(common::Command({}).serialize());
	return false;
	(void) command;
}


bool babel::client::CommandHandler::commandCallAnswerHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	return false;
	(void) command;
}


bool babel::client::CommandHandler::commandCallEndHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	return false;
	(void) command;
}

bool babel::client::CommandHandler::commandContactHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	return false;
	(void) command;
}

bool babel::client::CommandHandler::commandMessageHandler(
	std::unique_ptr<babel::common::ACommand> &command)
{
	return false;
	(void) command;
}
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.cpp
*/

#include <src/common/command/CommandLogout.hpp>
#include <src/common/command/CommandDelete.hpp>
#include "CommandHandler.hpp"

babel::client::CommandHandler::CommandHandler(babel::client::ClientInfo &info) :
	_infos(info),
	_commandHandlers({{babel::common::CommandName::CMD_LOGIN_OK,
				  &CommandHandler
				  ::commandLoginOkHandler},
			  {babel::common::CommandName::CMD_DELETE,
				  &CommandHandler
				  ::commandDeleteHandler},
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

}

bool
babel::client::CommandHandler::handleCommand(babel::common::ACommand command)
{
    if (_commandHandlers.find(command.getCommandId())
	!= _commandHandlers.end())
	return (this->*_commandHandlers[command.getCommandId()])(command);
    throw common::CommandException(command.getCommandId(),
				   "Command not supported.");
}

bool babel::client::CommandHandler::commandLoginOkHandler(
	babel::common::ACommand command) {
    	(void)command;
	emit changePage("main");
    return true;
}

bool babel::client::CommandHandler::commandDeleteHandler(
	babel::common::ACommand command) {
    for(int i = 0; _infos.getContacts().size(); i++)
	if (_infos.getContacts()[i].getId() == (unsigned short)stoi(command.getArgs()[0]))
	    _infos.removeContact(_infos.getContacts()[i]);
    return true;
}

bool babel::client::CommandHandler::commandCallHandler(
	babel::common::ACommand command) {
    //_infos.getSocket().send(common::Command({}).serialize());
    return false;
}

bool babel::client::CommandHandler::commandCallAnswerHandler(
	babel::common::ACommand command) {
    return false;
}

bool babel::client::CommandHandler::commandCallEndHandler(
	babel::common::ACommand command) {
    return false;
}

bool babel::client::CommandHandler::commandContactHandler(
	babel::common::ACommand command) {
    return false;
}

bool babel::client::CommandHandler::commandMessageHandler(
	babel::common::ACommand command) {
    return false;
}

void babel::client::CommandHandler::sendToAllClients(
	babel::common::DataPacket packet) {

}

bool babel::client::CommandHandler::createUser(
	babel::common::CommandLogin &cmd, uint32_t userId) {
    return false;
}

bool babel::client::CommandHandler::connectUser(
	babel::common::User &user, uint32_t userId) {
    return false;
}

void babel::client::CommandHandler::disconnectUser(uint32_t userId) {

}

bool babel::client::CommandHandler::isConnected(uint32_t userId) {
    return false;
}

bool babel::client::CommandHandler::sendOk(
	uint32_t userId, babel::common::CommandName cmd,
	const std::string &msg) {
    return false;
}



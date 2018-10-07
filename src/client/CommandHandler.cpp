/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ServerCommandHandler.cpp
*/

#include "CommandHandler.hpp"

babel::client::CommandHandler::CommandHandler(babel::client::ClientInfo &info) :
	_infos(info)
{

}

bool
babel::client::CommandHandler::handleCommand(
	babel::common::ACommand command, uint32_t userId)
{
	return false;
}


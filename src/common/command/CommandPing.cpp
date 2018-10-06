/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandPing.cpp
*/

#include "CommandPing.hpp"

babel::common::CommandPing::CommandPing(std::vector<std::string> args) :
	ACommand(CMD_PING)
{
	(void)args;
}
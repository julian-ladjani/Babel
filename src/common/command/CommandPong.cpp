/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandPong.cpp
*/

#include "CommandPong.hpp"

babel::common::CommandPong::CommandPong(std::vector<std::string> args) :
	ACommand(CMD_PONG)
{
	(void)args;
}
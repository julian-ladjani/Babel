/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandLogout.cpp
*/

#include "CommandLogout.hpp"

babel::common::CommandLogout::CommandLogout(std::vector<std::string> args) :
	ACommand(LOGOUT)
{
	(void)args;
}
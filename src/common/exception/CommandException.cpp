/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandException.cpp
*/

#include "CommandException.hpp"

babel::common::CommandException::CommandException(const std::string &message) :
	Exception("Command Error", message)
{}

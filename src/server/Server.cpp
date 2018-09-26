/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Server.cpp
*/

#include "Server.hpp"

babel::server::Server::Server() : _clients()
{}

int babel::server::Server::start()
{
	std::cout << "Bonjour, je suis un server !" << std::endl;
	return 0;
}

void babel::server::Server::addClient(common::User user)
{
	_clients.push_back(user);
}

void babel::server::Server::removeClient(common::User user)
{
//Je sais pas coder.
/*	const std::vector<common::User>::iterator position =
		std::find(_clients.begin(), _clients.end(), user);
	if (position != _clients.end())
		_clients.erase(position);*/
}
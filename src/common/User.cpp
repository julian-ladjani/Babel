//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - User.cpp
// File description:
// Created by Gregory EPLE
//

#include "User.hpp"

babel::common::User::User(std::string login, int id, bool connected) :
	_login(login), _id(id), _connected(connected), _connectionInfos()
{}

const std::string &babel::common::User::getLogin() const
{
	return _login;
}

void babel::common::User::setLogin(const std::string &login)
{
	_login = login;
}

int babel::common::User::getId() const
{
	return _id;
}

void babel::common::User::setId(int id)
{
	_id = id;
}

bool babel::common::User::isConnected() const
{
	return _connected;
}

void babel::common::User::setConnected(bool connected)
{
	_connected = connected;
}

const babel::common::ConnectionInfos &
babel::common::User::getConnectionInfos() const
{
	return _connectionInfos;
}

void babel::common::User::setConnectionInfos(
	const babel::common::ConnectionInfos &connectionInfos)
{
	_connectionInfos = connectionInfos;
}

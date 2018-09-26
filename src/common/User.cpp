/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** User.cpp
*/

#include "User.hpp"

babel::common::User::User(std::string login, int id, bool connected) :
	_login(login), _id(id), _connected(connected), _connectionInfo()
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

const babel::common::ConnectionInfo &
babel::common::User::getConnectionInfo() const
{
	return _connectionInfo;
}

void babel::common::User::setConnectionInfo(
	const babel::common::ConnectionInfo &connectionInfos)
{
	_connectionInfo = connectionInfos;
}

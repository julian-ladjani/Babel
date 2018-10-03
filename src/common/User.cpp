/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** User.cpp
*/

#include "User.hpp"

babel::common::User::User(const std::string &login, uint32_t id, bool connected) :
	_login(login), _id(id), _connected(connected),
	_connectionInfo(), _contacts()
{}

const std::string &babel::common::User::getLogin() const
{
	return _login;
}

void babel::common::User::setLogin(const std::string &login)
{
	_login = login;
}

int32_t babel::common::User::getId() const
{
	return _id;
}

void babel::common::User::setId(uint32_t id)
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

bool babel::common::User::addContact(uint32_t userId)
{
	if (std::find(_contacts.begin(), _contacts.end(), userId)
	    == _contacts.end()) {
		_contacts.push_back(userId);
		return true;
	}
	return false;
}

bool babel::common::User::removeContact(uint32_t userId)
{
	auto iterator = std::find(_contacts.begin(), _contacts.end(), userId);
	if (iterator == _contacts.end())
		return false;
	_contacts.erase(iterator);
	return true;
}

bool babel::common::User::operator==(const babel::common::User &user) const
{
	return _id == user._id;
}

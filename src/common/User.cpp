/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** User.cpp
*/

#include "User.hpp"

babel::common::User::User(uint32_t id, const std::string &login,
			  const std::string &password) :
	_id(id), _login(login), _password(password), _connected(false),
	_connectionInfo(), _contacts()
{}

babel::common::User::User(const std::string &login, uint32_t id, bool state) :
	_id(id), _login(login), _password(""), _connected(state),
	_connectionInfo(), _contacts()
{}

uint32_t babel::common::User::getId() const
{
	return _id;
}

void babel::common::User::setId(uint32_t id)
{
	_id = id;
}

const std::string &babel::common::User::getLogin() const
{
	return _login;
}

void babel::common::User::setLogin(const std::string &login)
{
	_login = login;
}

const std::string &babel::common::User::getPassword() const
{
	return _password;
}

void babel::common::User::setPassword(const std::string &password)
{
	_password = password;
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

const std::vector<uint32_t> &babel::common::User::getContacts() const
{
	return _contacts;
}

void babel::common::User::setContacts(const std::vector<uint32_t> &contacts)
{
	_contacts = contacts;
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

bool babel::common::User::operator==(const uint32_t &userId) const
{
	return _id == userId;
}
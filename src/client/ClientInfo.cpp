/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ClientInfo.cpp
*/

#include "ClientInfo.hpp"

babel::client::ClientInfo::ClientInfo() :
	_clientInfo(), _serverInfo(), _contacts()
{}

babel::common::User &babel::client::ClientInfo::getClientInfo()
{
	return _clientInfo;
}

void babel::client::ClientInfo::setClientInfo(const common::User &clientInfo)
{
	_clientInfo = clientInfo;
}

const babel::common::ConnectionInfo &
babel::client::ClientInfo::getServerInfo() const
{
	return _serverInfo;
}

void babel::client::ClientInfo::setServerInfo(
	const babel::common::ConnectionInfo &serverInfo)
{
	_serverInfo = serverInfo;
}

const std::vector<babel::common::User> &
babel::client::ClientInfo::getContacts() const
{
	return _contacts;
}

void babel::client::ClientInfo::setContacts(
	const std::vector<babel::common::User> &contacts)
{
	_contacts = contacts;
}

void babel::client::ClientInfo::addContact(common::User user)
{
	if (std::find(_contacts.begin(), _contacts.end(), user)
	    == _contacts.end())
		_contacts.push_back(user);
}

void babel::client::ClientInfo::removeContact(common::User user)
{
	auto position = std::find(_contacts.begin(), _contacts.end(), user);
	if (position != _contacts.end())
		_contacts.erase(position);
}

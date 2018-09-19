//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - ClientInfos.cpp
// File description:
// Created by Gregory EPLE
//

#include "ClientInfos.hpp"

babel::client::ClientInfos::ClientInfos() :
	_clientInfos(), _serverInfos(), _contacts()
{}

const babel::common::User &babel::client::ClientInfos::getClientInfos() const
{
	return _clientInfos;
}

void babel::client::ClientInfos::setClientInfos(const common::User &clientInfos)
{
	_clientInfos = clientInfos;
}

const babel::common::ConnectionInfos &
babel::client::ClientInfos::getServerInfos() const
{
	return _serverInfos;
}

void babel::client::ClientInfos::setServerInfos(
	const babel::common::ConnectionInfos &serverInfos)
{
	_serverInfos = serverInfos;
}

const std::vector<babel::common::User> &
babel::client::ClientInfos::getContacts() const
{
	return _contacts;
}

void babel::client::ClientInfos::setContacts(
	const std::vector<babel::common::User> &contacts)
{
	_contacts = contacts;
}

void babel::client::ClientInfos::addContact(common::User user)
{
	_contacts.push_back(user);
}

void babel::client::ClientInfos::removeContact(common::User user)
{
//Je sais pas coder.
/*	const std::vector<common::User>::iterator position =
		std::find(_contacts.begin(), _contacts.end(), user);
	if (position != _contacts.end())
		_contacts.erase(position); */
}

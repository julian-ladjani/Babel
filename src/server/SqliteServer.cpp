/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** SqliteServer.cpp
*/

#include <iostream>
#include "SqliteServer.hpp"

babel::server::SqliteServer::SqliteServer() : _db(nullptr)
{
	std::string userTable = std::string(
		"CREATE TABLE IF NOT EXISTS USERS (UserId INT, ") +
				"Username VARCHAR(50), Password VARCHAR(50))";
	std::string contactTable = std::string(
		"CREATE TABLE IF NOT EXISTS CONTACTS ")
				   + "(UserId INT, ContactId INT)";
	if (sqlite3_open("src/server/database.db", &_db))
		throwSqliteError();
	executeCommand(userTable, nullptr, nullptr);
	executeCommand(contactTable, nullptr, nullptr);
}

babel::server::SqliteServer::~SqliteServer()
{
	sqlite3_close(_db);
}

void babel::server::SqliteServer::executeCommand(
	std::string command, void *var,
	int (*callback)(void *, int, char **, char **)) const
{
	if (sqlite3_exec(_db, command.c_str(), callback, var, nullptr))
		throwSqliteError();
}

void babel::server::SqliteServer::addUser(babel::common::User &user) const
{
	std::string insertUser = std::string("INSERT INTO USERS ")
				 + "(UserId, Username, Password) VALUES ("
				 + std::to_string(user.getId()) + ", '"
				 + user.getLogin() + "', '"
				 + user.getPassword() + "')";
	executeCommand(insertUser, nullptr, nullptr);
}

void babel::server::SqliteServer::addContact(uint32_t userId,
					     uint32_t contactId) const
{
	std::string insertContact = std::string("INSERT INTO CONTACTS ")
				    + "(UserId, ContactId) VALUES ("
				    + std::to_string(userId) + ", "
				    + std::to_string(contactId) + ")";
	executeCommand(insertContact, nullptr, nullptr);
}

void babel::server::SqliteServer::removeUser(babel::common::User &user) const
{
	std::string removeUser = std::string("DELETE USERS WHERE UserId = ")
				 + std::to_string(user.getId());
	executeCommand(removeUser, nullptr, nullptr);
}

void babel::server::SqliteServer::removeContact(uint32_t userId,
						uint32_t contactId) const
{
	std::string removeContact = std::string("DELETE CONTACTS WHERE ")
				    + "UserId =" + std::to_string(userId)
				    + " AND ContactId = "
				    + std::to_string(contactId);
	executeCommand(removeContact, nullptr, nullptr);
}

void babel::server::SqliteServer::getUsers(
	std::vector<babel::common::User> &userList) const
{
	std::string getUsers = "SELECT * FROM USERS";
	executeCommand(getUsers, &userList, &callbackGetUsers);
}

void babel::server::SqliteServer::getUserContacts(
	uint32_t userId, std::vector<uint32_t> &contactList) const
{
	std::string getContacts = std::string("SELECT ContactId FROM CONTACTS ")
				  + "WHERE UserId = " + std::to_string(userId);
	executeCommand(getContacts, &contactList, &callbackGetUserContacts);
}


int babel::server::SqliteServer::callbackGetUsers(
	void *var, int ac, char **av, char **azColName)
{
	std::vector<babel::common::User> *userList
		= (std::vector<babel::common::User> *)var;
	if (userList && ac == 3)
		userList->push_back(babel::common::User(
			(uint32_t)stoi(std::string(av[0])), av[1], av[2]));
	return 0;
	(void)azColName;
}

int babel::server::SqliteServer::callbackGetUserContacts(
	void *var, int ac, char **av, char **azColName)
{
	std::vector<uint32_t> *contactList = (std::vector<uint32_t> *)var;
	if (contactList && ac == 1)
		contactList->push_back((uint32_t)stoi(std::string(av[0])));
	return 0;
	(void)azColName;
}

void babel::server::SqliteServer::throwSqliteError() const
{
	throw babel::common::Exception("SQLite Error", sqlite3_errmsg(_db));
}
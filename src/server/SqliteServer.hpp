/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** SqliteServer.hpp
*/

#ifndef CPP_BABEL_2018_SQLITESERVER_HPP
#define CPP_BABEL_2018_SQLITESERVER_HPP

#include <sqlite3.h>
#include <src/common/exception/Exception.hpp>
#include <src/common/User.hpp>
#include <memory>

namespace babel {
	namespace server {
		class SqliteServer {
		public:
			SqliteServer();
			virtual ~SqliteServer();
			void executeCommand(
				std::string command, void *var,
				int (*callback)(void *, int,
						char **, char **)) const;
			void getUsers(
				std::vector<common::User> &userList) const;
			void getUserContacts(uint32_t userId,
					     std::vector<uint32_t>
					     &contactList) const;
			void addUser(common::User &user) const;
			void addContact(uint32_t userId,
					uint32_t contactId) const;
			void removeUser(common::User &user) const;
			void removeContact(uint32_t userId,
					   uint32_t contactId) const;
		private:
			static int callbackGetUsers(
				void *var, int ac,
				char **av, char **azColName);
			static int callbackGetUserContacts(
				void *var, int ac,
				char **av, char **azColName);
			void throwSqliteError() const;
			sqlite3 *_db;
		};
	}
}

#endif //CPP_BABEL_2018_SQLITESERVER_HPP

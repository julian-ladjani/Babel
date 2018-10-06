/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** User.hpp
*/

#ifndef CPP_BABEL_2018_USER_HPP
#define CPP_BABEL_2018_USER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "src/common/network/ConnectionInfo.hpp"

namespace babel {
	namespace common {
		class User {
		public:
			explicit User(uint32_t id = 0,
				      const std::string &login = "",
				      const std::string &password = "");
			User(const std::string &login, uint32_t id, bool state);
			uint32_t getId() const;
			void setId(uint32_t id);
			const std::string &getLogin() const;
			void setLogin(const std::string &login);
			const std::string &getPassword() const;
			void setPassword(const std::string &password);
			bool isConnected() const;
			void setConnected(bool connected);
			const ConnectionInfo &getConnectionInfo() const;
			void setConnectionInfo(
				const ConnectionInfo &connectionInfo);
			bool addContact(uint32_t userId);
			bool removeContact(uint32_t userId);
			bool operator==(const User &user) const;

		private:
			uint32_t _id;
			std::string _login;
			std::string _password;
			bool _connected;
			ConnectionInfo _connectionInfo;
			std::vector<uint32_t> _contacts;
		};
	}
}

#endif //CPP_BABEL_2018_USER_HPP

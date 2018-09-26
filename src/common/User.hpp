/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** User.hpp
*/

#ifndef CPP_BABEL_2018_USER_HPP
#define CPP_BABEL_2018_USER_HPP

#include <string>
#include "src/common/network/ConnectionInfo.hpp"

namespace babel {
	namespace common {
		class User {
		public:
			explicit User(std::string login = "", int id = 0,
			     bool connected = false);
			const std::string &getLogin() const;
			void setLogin(const std::string &login);
			int getId() const;
			void setId(int id);
			bool isConnected() const;
			void setConnected(bool connected);
			const ConnectionInfo &getConnectionInfo() const;
			void setConnectionInfo(
				const ConnectionInfo &connectionInfo);

		private:
			std::string _login;
			int _id;
			bool _connected;
			ConnectionInfo _connectionInfo;
		};
	}
}

#endif //CPP_BABEL_2018_USER_HPP

//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - User.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_BABEL_2018_USER_HPP
#define CPP_BABEL_2018_USER_HPP

#include <string>

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

		private:
			std::string _login;
			int _id;
			bool _connected;
		};
	}
}

#endif //CPP_BABEL_2018_USER_HPP

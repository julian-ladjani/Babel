/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Server.hpp
*/

#ifndef CPP_BABEL_2018_SERVER_HPP
#define CPP_BABEL_2018_SERVER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <src/common/User.hpp>

namespace babel {
	namespace server {
		class Server {
		public:
			Server();
			int start();
			void addClient(common::User user);
			void removeClient(common::User user);

		private:
			std::vector<common::User> _clients;
		};
	}
}


#endif //CPP_BABEL_2018_SERVER_HPP

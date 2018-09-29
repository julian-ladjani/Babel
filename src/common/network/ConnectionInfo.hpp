/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** AudioEncoder.hpp
*/

#ifndef CPP_BABEL_2018_CONNECTIONINFOS_HPP
#define CPP_BABEL_2018_CONNECTIONINFOS_HPP

#include <array>
#include <string>

namespace babel {
	namespace common {
		class ConnectionInfo {
		public:
			explicit ConnectionInfo(unsigned short port = 0,
						std::string ip = "0.0.0.0");
			unsigned short getPort() const;
			void setPort(unsigned short port);
			const std::string &getIp() const;
			void setIp(const std::string &Ip);
		private:
			unsigned short _port;
			std::string _ip;
		};
	}
}


#endif //CPP_BABEL_2018_CONNECTIONINFOS_HPP

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** AudioEncoder.hpp
*/

#ifndef CPP_BABEL_2018_CONNECTIONINFOS_HPP
#define CPP_BABEL_2018_CONNECTIONINFOS_HPP

#include <array>

namespace babel {
	namespace common {
		class ConnectionInfo {
		public:
			explicit ConnectionInfo(uint16_t port = 0,
						std::string ip = "0.0.0.0");
			uint16_t getPort() const;
			void setPort(uint16_t port);
			const std::string &getIp() const;
			void setIp(const std::string &Ip);
		private:
			uint16_t _port;
			std::string _ip;
		};
	}
}


#endif //CPP_BABEL_2018_CONNECTIONINFOS_HPP

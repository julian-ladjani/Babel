//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - ConnectionInfos.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_BABEL_2018_CONNECTIONINFOS_HPP
#define CPP_BABEL_2018_CONNECTIONINFOS_HPP

#include <array>

namespace babel {
	namespace common {
		class ConnectionInfos {
		public:
			explicit ConnectionInfos(unsigned short port = 0,
						 std::array<unsigned char, 4> ip
						 = {0, 0, 0, 0});
			unsigned short getPort() const;
			void setPort(unsigned short port);
			const std::array<unsigned char, 4> &getIp() const;
			void setIp(const std::array<unsigned char, 4> &ip);

		private:
			unsigned short _port;
			std::array<unsigned char, 4> _ip;
		};
	}
}


#endif //CPP_BABEL_2018_CONNECTIONINFOS_HPP

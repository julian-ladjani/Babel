/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpSocketException class
*/

#ifndef CPP_BABEL_2018_TCPSOCKETEXCEPTION_HPP
#define CPP_BABEL_2018_TCPSOCKETEXCEPTION_HPP

#include "src/common/network/ConnectionInfo.hpp"
#include "Exception.hpp"

namespace babel
{
	namespace common
	{
		class TcpSocketException : public Exception {
		public:
			explicit TcpSocketException(
				ConnectionInfo connectionInfo,
			const std::string &message = "Unknown Error");
			ConnectionInfo getConnectionInfo();
		private:
			ConnectionInfo _connectionInfo;
		};
	}
}
#endif //CPP_BABEL_2018_TCPSOCKETEXCEPTION_HPP

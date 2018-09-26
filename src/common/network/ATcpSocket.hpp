/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ITcpSocket header file
*/

#ifndef CPP_BABEL_2018_ATCPSOCKET_HPP
#define CPP_BABEL_2018_ATCPSOCKET_HPP

#include "ConnectionInfo.hpp"

namespace babel
{
	namespace common
	{
		class ATcpSocket {
		public:
			virtual
			ATcpSocket(ConnectionInfo &connectionInfo) = 0;
			virtual void connect() = 0;
			virtual void disconnect() = 0;
			virtual const ConnectionInfo &getConnectionInfo() = 0;
		protected:
			ConnectionInfo &_connectionInfo;
			bool _isConnect;
		};
	}
}
#endif //CPP_BABEL_2018_ATCPSOCKET_HPP

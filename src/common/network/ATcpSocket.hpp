/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ITcpSocket header file
*/

#ifndef CPP_BABEL_2018_ATCPSOCKET_HPP
#define CPP_BABEL_2018_ATCPSOCKET_HPP

#include <vector>
#include "ConnectionInfo.hpp"
#include "DataPacket.hpp"

namespace babel
{
	namespace common
	{
		class ATcpSocket {
		public:
			ATcpSocket(ConnectionInfo &connectionInfo);
			virtual void connect() = 0;
			virtual void send(babel::common::DataPacket) = 0;
			virtual const
			babel::common::DataPacket &receive() = 0;
			virtual void disconnect() = 0;
			virtual const ConnectionInfo &getConnectionInfo() = 0;
		protected:
			static constexpr char PACKET_SEPARATOR[] = "\x1d";
			ConnectionInfo &_connectionInfo;
			bool _isConnect;
			std::vector<babel::common::DataPacket> _receiveQueue;
		};
	}
}
#endif //CPP_BABEL_2018_ATCPSOCKET_HPP

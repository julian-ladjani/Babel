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
			explicit ATcpSocket(ConnectionInfo &connectionInfo);
			virtual bool connect() = 0;
			virtual bool send(babel::common::DataPacket) = 0;
			virtual const
			babel::common::DataPacket &receive() = 0;
			virtual bool disconnect() = 0;
			const ConnectionInfo getConnectionInfo() const;
			bool isConnect() const;
		protected:
			const DataPacket getPacketFromQueue();
			static constexpr char PACKET_SEPARATOR[] = "\x1d";
			ConnectionInfo &_connectionInfo;
			bool _isConnect;
			std::vector<babel::common::DataPacket> _receiveQueue;
		};
	}
}
#endif //CPP_BABEL_2018_ATCPSOCKET_HPP

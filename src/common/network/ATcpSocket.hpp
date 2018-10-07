/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	ITcpSocket header file
*/

#ifndef CPP_BABEL_2018_ATCPSOCKET_HPP
#define CPP_BABEL_2018_ATCPSOCKET_HPP

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <vector>
#include <string>
#include "ConnectionInfo.hpp"
#include "src/common/command/CommandName.hpp"
#include "DataPacket.hpp"

namespace babel
{
	namespace common
	{
		class ATcpSocket {
		public:
			explicit ATcpSocket(ConnectionInfo &connectionInfo);
			virtual ~ATcpSocket() = default;
			virtual bool connect() = 0;
			virtual bool send(babel::common::DataPacket) = 0;
			virtual const
			babel::common::DataPacket receive() = 0;
			virtual bool disconnect() = 0;
			const ConnectionInfo getConnectionInfo() const;
			bool isConnect() const;
			bool operator==(const ATcpSocket &socket) const;
			bool operator==(
				const ConnectionInfo &connectionInfo) const;
		protected:
			std::string addPacketsToQueue(
				std::string &, std::string = std::string());
			const DataPacket getPacketFromQueue();
			static constexpr char PACKET_SEPARATOR[] = "\x1d";
			ConnectionInfo &_connectionInfo;
			bool _isConnect;
			std::string _uncompletePacket;
			std::vector<babel::common::DataPacket> _receiveQueue;
		private:
			void addPacketToQueue(std::string);
			void addPacketToQueue(std::vector<std::string> &);
		};
	}
}
#endif //CPP_BABEL_2018_ATCPSOCKET_HPP

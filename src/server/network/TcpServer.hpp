/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpServer class
*/

#ifndef CPP_BABEL_2018_TCPSERVER_HPP
#define CPP_BABEL_2018_TCPSERVER_HPP

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <iostream>
#include <boost/bind.hpp>
#include "BoostTcpSocket.hpp"
#include "src/server/exception/TcpServerException.hpp"
#include "src/common/command/CommandUserState.hpp"

namespace babel
{
	namespace server
	{
		class TcpServer {
		public:
			explicit TcpServer(boost::asio::io_context &ioContext,
				uint16_t port = 53876);
			std::vector<std::pair<BoostTcpSocket &, int32_t>>
			&getSockets();
			void closeSocket(common::ConnectionInfo connectionInfo);
		private:
			bool startAccept();
			void handleAccept(BoostTcpSocket::pointer newSocket,
				const boost::system::error_code &ec);
			void sendDisconnectionMessage(int32_t socketId);
			std::vector<std::pair<babel::server::BoostTcpSocket &,
				int32_t>> _sockets;
			int32_t _minId = -1;
			boost::asio::io_context &_ioContext;
			boost::asio::ip::tcp::acceptor _tcpAcceptor;
		};
	}
}

#endif //CPP_BABEL_2018_TCPSERVER_HPP

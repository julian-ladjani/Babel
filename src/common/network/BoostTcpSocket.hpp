/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	BoostTcpSocket class
*/

#ifndef CPP_BABEL_2018_BOOSTTCPSOCKET_HPP
#define CPP_BABEL_2018_BOOSTTCPSOCKET_HPP

#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "ATcpSocket.hpp"

namespace babel
{
	namespace common
	{
		class BoostTcpSocket : public ATcpSocket {
		public:
			explicit
			BoostTcpSocket(ConnectionInfo &connectionInfo);
			bool connect() override;
			bool disconnect() override;
			bool send(DataPacket packet) override;
			const DataPacket &receive() override;
		private:
			void startRead();
			void handleRead(const boost::system::error_code &ec);
			void handleWrite(const boost::system::error_code &ec);
			boost::asio::io_service _ioService;
			boost::asio::streambuf _input_buffer;
			boost::asio::ip::tcp::socket _socket;
			boost::asio::ip::tcp::endpoint _endpoint;
		};
	}
}

#endif //CPP_BABEL_2018_BOOSTTCPSOCKET_HPP

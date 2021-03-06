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
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "src/common/network/ATcpSocket.hpp"
#include "src/common/exception/TcpSocketException.hpp"

namespace babel
{
	namespace server
	{
		class BoostTcpSocket
			: public common::ATcpSocket,
				public boost::enable_shared_from_this
					<BoostTcpSocket> {
		public:
			typedef boost::shared_ptr<BoostTcpSocket> pointer;
			BoostTcpSocket(common::ConnectionInfo
			connectionInfo, boost::asio::io_context &ioContext);
			static pointer create(common::ConnectionInfo
			connectionInfo, boost::asio::io_context &ioContext);
			bool connect() override;
			bool disconnect() override;
			bool send(common::DataPacket packet) override;
			const common::DataPacket receive() override;
			boost::asio::ip::tcp::socket &
			getSocket();
			bool mustBeConnected();
			int32_t getId() const;
			void setId(int32_t _id);

		private:
			void startRead();
			void handleRead(const boost::system::error_code &ec);
			void handleWrite(const boost::system::error_code &ec);
			boost::asio::io_context &_ioContext;
			boost::asio::streambuf _input_buffer;
			boost::asio::ip::tcp::socket _socket;
			boost::asio::ip::tcp::endpoint _endpoint;
			int32_t _id;
		};
	}
}

#endif //CPP_BABEL_2018_BOOSTTCPSOCKET_HPP

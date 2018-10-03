/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	QtTcpSocket class
*/

#ifndef CPP_BABEL_2018_QTTCPSOCKET_HPP
#define CPP_BABEL_2018_QTTCPSOCKET_HPP

#include <QtNetwork>
#include <QtNetwork/QTcpSocket>
#include "ATcpSocket.hpp"

namespace babel
{
	namespace client
	{
		class QtTcpSocket
			: public common::ATcpSocket, public QObject {
		Q_OBJECT
		public:
			explicit
			QtTcpSocket(common::ConnectionInfo
			&connectionInfo);
			bool connect() override;
			bool disconnect() override;
			bool send(common::DataPacket packet) override;
			const common::DataPacket receive() override;
		private:
			void startRead();
			void handleRead();
			char *_input_buffer;
			QTcpSocket _socket;
		};
	}
}
#endif //CPP_BABEL_2018_QTTCPSOCKET_HPP

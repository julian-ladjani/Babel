//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// EchoSoundTestServicePage.hpp
//

#ifndef CPP_BABEL_2018_ECHOSOUNDTESTSERVICEPAGE_HPP
#define CPP_BABEL_2018_ECHOSOUNDTESTSERVICEPAGE_HPP

#include <src/client/gui/components/Button.hpp>
#include <src/client/ClientInfo.hpp>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkDatagram>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include "ConnectionPage.hpp"
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class EchoSoundTestServicePage : public ABabelPage
		{
		public:
			explicit EchoSoundTestServicePage(client::ClientInfo &_infos);
			void initSocket();
			void readData();
		private:
			enum BtnType {
				SEND,
			};
			enum IptType {
				IP_ADDRESS,
				PORT,
				MSG
			};
			QUdpSocket _udpSocket;
			std::array<std::unique_ptr<Button>, 1> _buttons;
			std::array<std::unique_ptr<Input>, 3> _inputs;
			common::ConnectionInfo cinfos;
			void sendData();
			void connections() override;
		};

	}
}

#endif /* CPP_BABEL_2018_ECHOSOUNDTESTSERVICEPAGE_HPP */
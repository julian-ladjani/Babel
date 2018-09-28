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
			QUdpSocket _udpSocket;
			Button *_sender;
			void sendData();
		protected:
			void connections() override;
		};

	}
}

#endif /* CPP_BABEL_2018_ECHOSOUNDTESTSERVICEPAGE_HPP */
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ABabelPage.hpp
*/

#ifndef CPP_BABEL_2018_IBABELPAGE_HPP
#define CPP_BABEL_2018_IBABELPAGE_HPP

#include <QObject>
#include <QtCore>
#include <QMainWindow>
#include <QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkDatagram>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include <src/client/ClientInfo.hpp>
#include "src/client/gui/components/Input.hpp"
#include "src/client/gui/components/Image.hpp"
#include "src/client/gui/components/Button.hpp"
#include <src/client/gui/components/Label.hpp>
#include <src/client/gui/components/ListWidget.hpp>
#include <src/client/gui/components/GroupBox.hpp>

namespace babel {
	namespace client {
		class ABabelPage : public QWidget {
		Q_OBJECT
		public:
			ABabelPage(ClientInfo &_infos);
			~ABabelPage() override {}
		protected:
			virtual void connections() = 0;
			ClientInfo &_infos;
			QGridLayout *_layout;
		};
	}
}

#endif /* CPP_BABEL_2018_IBABELPAGE_HPP */
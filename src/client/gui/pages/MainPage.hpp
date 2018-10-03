//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.hpp
//

#ifndef CPP_BABEL_2018_MAINPAGE_HPP
#define CPP_BABEL_2018_MAINPAGE_HPP

#include <src/client/gui/components/Button.hpp>
#include <src/client/gui/components/Label.hpp>
#include <src/client/gui/components/ListWidget.hpp>
#include <src/client/gui/components/GroupBox.hpp>
#include <src/client/ClientInfo.hpp>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkDatagram>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include "ConnectionPage.hpp"
#include "ABabelPage.hpp"
#include <QtWidgets/QSplitter>

namespace babel {
	namespace client {
		class MainPage : public ABabelPage
		{
		public:
			explicit MainPage(client::ClientInfo &_infos);
			void initSocket();
		    	void initSideBar();
		    	void initMain();
			void readData();
			void setLogin();
		private:
			QUdpSocket _udpSocket;
			enum ButtonType{
			    BEXIT,
			};
			enum LabelType {
			    LFAVORITE,
			    LSERVER,
			    LNAME
			    };
			enum QGroupeBoxType {
			    GBMAIN,
			    GBSIDEBAR,
			    GBCONTACT,
			    GBSERVER,
			    GBNAME
			    };
			enum ListWidgetType {
			    LWFAVORITE,
			    LWSERVER,
			};
			enum SplitterType {
			    SCENTER,
			    SLIST,
			};
		    	std::array<std::unique_ptr<Button>, 1> _buttons;
		    	std::array<std::unique_ptr<Label>, 3> _label;
		    	std::array<std::unique_ptr<ListWidget>, 2> _list;
		    	std::array<std::unique_ptr<GroupBox>, 5> _container;
		    	std::array<std::unique_ptr<QSplitter>, 3> _splitter;
		    	std::unique_ptr<Image> _logo;
		    	void sendData();
		protected:
			void connections() override;
		};

	}
}


#endif /* CPP_BABEL_2018_MAINPAGE_HPP */
//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.hpp
//

#ifndef CPP_BABEL_2018_MAINPAGE_HPP
#define CPP_BABEL_2018_MAINPAGE_HPP

#include <src/client/gui/components/Thread.hpp>
#include "ConnectionPage.hpp"
#include "ABabelPage.hpp"
#include "src/client/gui/components/Thread.hpp"

namespace babel {
	namespace client {
		class MainPage : public ABabelPage
		{
		Q_OBJECT
		public:
			explicit MainPage(client::ClientInfo &_infos);
			void initSocket();
		    	void initSideBar();
		    	void initMain();
			void readData();
			void setLogin();
		Q_SIGNALS:
		    void changePage(std::string pageName);
		private:
			QUdpSocket _udpSocket;
			bool  _test;
			enum ButtonType{
			    BEXIT,
			    BTESTMIC
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
		    	std::array<std::unique_ptr<Button>, 2> _buttons;
		    	std::array<std::unique_ptr<Label>, 3> _label;
		    	std::array<std::unique_ptr<ListWidget>, 2> _list;
		    	std::array<std::unique_ptr<GroupBox>, 5> _container;
		    	std::array<std::unique_ptr<QSplitter>, 3> _splitter;
		    	std::unique_ptr<Image> _logo;
			Thread _threadMic;
		    	void sendData();
		    	void changeToTestPage();
		    	void testMic();
		protected:
			void connections() override;
		};

	}
}


#endif /* CPP_BABEL_2018_MAINPAGE_HPP */
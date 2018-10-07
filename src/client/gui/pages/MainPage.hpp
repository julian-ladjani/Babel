//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.hpp
//

#ifndef CPP_BABEL_2018_MAINPAGE_HPP
#define CPP_BABEL_2018_MAINPAGE_HPP

#include <array>
#include <vector>
#include <algorithm>
#include <boost/range/algorithm/find.hpp>
#include "ConnectionPage.hpp"
#include "src/client/gui/components/TMicro.hpp"
#include "ABabelPage.hpp"
#include "CallPage.hpp"
#include <src/common/network/DataPacket.hpp>

namespace babel {
	namespace client {
	    class TMicro;
		class MainPage : public ABabelPage
		{
		Q_OBJECT
		public:
			explicit MainPage(client::ClientInfo &_infos);
			~MainPage();
			void initSocket();
		    	void initSideBar();
		    	void initMain();
			void readData();
			void setLogin();
			CallPage &getCallSection();
		Q_SIGNALS:
		    void changePage(std::string pageName);
		    void disconnect();
		    void changeMic();
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
		    	std::array<std::unique_ptr<Label>, 3> _labels;
		    	std::array<std::unique_ptr<ListWidget>, 2> _lists;
		    	std::array<GroupBox*, 5> _containers;
		    	std::array<QSplitter*, 3> _splitters;
		    	std::unique_ptr<Image> _logo;
			std::unique_ptr<TMicro>_threadMic;
		    	void sendData();
		    	void changeToConnectionPage();
		    	void testMic();
			void updateActiveContact(QListWidgetItem *contactItem);
		    	CallPage _callSection;
		protected:
			void connections() override;
			void readTcpData();
		};

	}
}


#endif /* CPP_BABEL_2018_MAINPAGE_HPP */
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.hpp
*/

#ifndef CPP_BABEL_2018_WINDOW_HPP
#define CPP_BABEL_2018_WINDOW_HPP

#include <memory>
#include <QtNetwork/QUdpSocket>
#include <src/client/gui/components/TConversation.hpp>
#include "ABabelPage.hpp"
#include "src/client/network/soundPacket.hpp"

namespace babel {
	namespace client {
	    class TConversation;
		class ConnectionPage : public ABabelPage
		{
		Q_OBJECT
		public:
			explicit ConnectionPage(ClientInfo &_infos);

			void arrangeWidgets();
			void serverPropertiesSwitcher();
			virtual ~ConnectionPage() {};
			void handleButton();
		Q_SIGNALS:
			void changePage(std::string pageName);
			void applyConversation();
		protected:
			void connections() override;
		private:
			enum BtnType {
				CONNECTION,
				OPTIONS,
				TEST
			};
			enum InputType {
				LOGIN,
				PASSWORD,
				IP_ADDRESS,
				PORT
			};
			std::array<std::unique_ptr<Button>, 3> _buttons;
			std::array<std::unique_ptr<Input>, 4> _inputs;
			std::unique_ptr<Image> _logo;
		    	TConversation *_threadConversation;
		    	QUdpSocket _udpSocket;
		    	AudioManager _audio;
		    	AudioEncoder _encode;
		    	int64_t _timeStamp;
		    	void changeToTestPage();
		    	void initSocket();
		    	void readAudio();
			std::vector<uint16_t> convert(SoundPacket sp);
		};

	}
}

#endif /* CPP_BABEL_2018_WINDOW_HPP */
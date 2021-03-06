/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.hpp
*/

#ifndef CPP_BABEL_2018_CALL_HPP
#define CPP_BABEL_2018_CALL_HPP

#include <memory>
#include <src/client/gui/components/Chat.hpp>
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class CallPage : public ABabelPage
		{
		Q_OBJECT
		public:
			CallPage(ClientInfo &_infos);
			void arrangeWidgets();
			virtual ~CallPage() {};
			void update();
		Q_SIGNALS:
			void sendMessageSignal(std::string &msg);
		protected:
			void connections() override;
		private:
			void sendMessage();
			enum BtnType {
				SEND_MSG,
				CALL
			};
			std::array<std::unique_ptr<QPushButton>, 2> _buttons;
			Input _chatInput;
			Chat _chatBox;
			Image _connectIcon;
			Label _contactName;
//			std::unique_ptr<Image> _logo;
			void initWidgets();
		};

	}
}

#endif /* CPP_BABEL_2018_CALL_HPP */
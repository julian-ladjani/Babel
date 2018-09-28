/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.hpp
*/

#ifndef CPP_BABEL_2018_WINDOW_HPP
#define CPP_BABEL_2018_WINDOW_HPP

#include <unistd.h>
#include <memory>
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class ConnectionPage : public ABabelPage
		{
		Q_OBJECT
		public:
			explicit ConnectionPage(ClientInfo &_infos);

			void arrangeWidgets();
			std::function<void()> serverPropertiesSwitcher();

			virtual ~ConnectionPage() {};
			void handleButton();
		Q_SIGNALS:
			void changePage(std::string pageName);
		protected:
			void connections() override;
		private:
			enum BtnType {
				CONNECTION,
				OPTIONS
			};
			enum InputType {
				LOGIN,
				PASSWORD,
				IP_ADDRESS,
				PORT
			};
			std::array<std::unique_ptr<Button>, 2> _buttons;
			std::array<std::unique_ptr<Input>, 4> _inputs;
			std::unique_ptr<Image> _logo;
		};

	}
}

#endif /* CPP_BABEL_2018_WINDOW_HPP */
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Window.hpp
*/

#ifndef CPP_BABEL_2018_WINDOW_HPP
#define CPP_BABEL_2018_WINDOW_HPP

#include <QObject>
#include <QtCore>
#include <QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <unistd.h>
#include <src/client/components/WidgetManager.hpp>
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class ConnectionPage : public ABabelPage
		{
		public:
			ConnectionPage(ClientInfo &_infos);
			void submit(QVBoxLayout *layout);
			void home(QVBoxLayout *layout);
			std::function<void()> serverPropertiesSwitcher();
		    	std::function<void()> connection();


		private:
			QVBoxLayout *_layout;
			WidgetManager	_connection;
		};

	}
}

#endif /* CPP_BABEL_2018_WINDOW_HPP */
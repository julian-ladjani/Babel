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

#include "src/client/gui/components/CButton.hpp"
#include "src/client/gui/components/Input.hpp"
#include "src/client/gui/components/Image.hpp"
#include "IBabelPage.hpp"

namespace babel {
	namespace client {
		class ConnectionPage : public IBabelPage
		{
		public:
			ConnectionPage();
			void submit(QVBoxLayout *layout);
			void home(QVBoxLayout *layout);
			std::function<void()> lol();

		private:
			QVBoxLayout *_layout;
			Input *_ip;
			Input *_port;
			std::vector<QWidget *> _input;
		};

	}
}

#endif /* CPP_BABEL_2018_WINDOW_HPP */
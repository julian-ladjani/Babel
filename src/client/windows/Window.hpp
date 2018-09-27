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
#include <QtWidgets>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <unistd.h>
#include <src/client/components/WidgetManager.hpp>

namespace babel {
	namespace client {
		class MainWindow : public QWidget
		{
		public:
			MainWindow();
			void Submit(QVBoxLayout *layout);
			void Home(QVBoxLayout *layout);
			std::function<void()> showOption();
		    	std::function<void()> connection();


		private:
			QVBoxLayout *_layout;
			WidgetManager	_connection;
		};

	}
}

#endif /* CPP_BABEL_2018_WINDOW_HPP */
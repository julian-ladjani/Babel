//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainWindow.hpp
//

#ifndef CPP_BABEL_2018_MAINWINDOW_HPP
#define CPP_BABEL_2018_MAINWINDOW_HPP

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <src/client/ClientInfo.hpp>
#include <QtWidgets/QStackedWidget>
#include <QObject>
#include <memory>
#include <src/client/gui/pages/ABabelPage.hpp>
#include <src/client/gui/pages/PageManager.hpp>
#include "src/client/gui/pages/ConnectionPage.hpp"
#include "src/client/gui/pages/MainPage.hpp"

namespace babel {
	namespace client {
		class MainWindow : public QMainWindow
		{
		Q_OBJECT
		public:
			MainWindow();
		private:
			void changePage(std::string pageName);
			PageManager _pages;
			ClientInfo _infos;

			void initClientInfos();
		};

	}
}

#endif /* CPP_BABEL_2018_MAINWINDOW_HPP */
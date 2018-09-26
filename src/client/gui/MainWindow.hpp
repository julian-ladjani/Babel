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
#include <memory>
#include <src/client/gui/pages/IBabelPage.hpp>

namespace babel {
	namespace client {
		class MainWindow : public QMainWindow
		{
		public:
			MainWindow();
			void show();
		private:
			std::unique_ptr<IBabelPage> _cnxPage;
			QStackedWidget _pages;
			ClientInfo _infos;
		};

	}
}

#endif /* CPP_BABEL_2018_MAINWINDOW_HPP */
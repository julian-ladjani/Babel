//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// Window.hpp
//

#ifndef CPP_BABEL_2018_WINDOW_HPP
#define CPP_BABEL_2018_WINDOW_HPP

#include <QtWidgets/QMainWindow>
#include "../Components/CButton.hpp"
#include "../Components/Input.hpp"
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <unistd.h>
#include <QtWidgets>
#include <QMainWindow>
namespace babel {
	namespace client {
		class MainWindow : public QWidget
		{
		public:
			MainWindow();
		private:
			void Home(QVBoxLayout *layout);
			void Submit(QVBoxLayout *layout);
		};

	}
}

#endif /* CPP_BABEL_2018_WINDOW_HPP */
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Babel.hpp
*/

#ifndef CPP_BABEL_2018_BABEL_HPP
#define CPP_BABEL_2018_BABEL_HPP

#include <src/client/ClientInfo.hpp>
#include "src/client/gui/MainWindow.hpp"

namespace babel {
	namespace client {
		class Babel {
		public:
			Babel();
			void start();
		private:
			MainWindow _window;
		};
	}
}

#endif /* CPP_BABEL_2018_BABEL_HPP */
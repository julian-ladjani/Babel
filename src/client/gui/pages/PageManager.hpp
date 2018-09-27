//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// PageManager.hpp
//

#ifndef CPP_BABEL_2018_PAGEMANAGER_HPP
#define CPP_BABEL_2018_PAGEMANAGER_HPP

#include <QtWidgets/QStackedWidget>
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class PageManager : public QStackedWidget {
		public:
		private:
			std::map<std::string, babel::client::ABabelPage>
			_names;
		};
	}
}

#endif /* CPP_BABEL_2018_PAGEMANAGER_HPP */
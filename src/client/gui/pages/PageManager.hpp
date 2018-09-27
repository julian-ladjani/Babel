//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// PageManager.hpp
//

#ifndef CPP_BABEL_2018_PAGEMANAGER_HPP
#define CPP_BABEL_2018_PAGEMANAGER_HPP

#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class PageManager : public QStackedWidget {
		public:
			int addWidget(ABabelPage *w, std::string name);
		private:
			std::map<std::string, ABabelPage*>
			_names;

			ABabelPage *getPage(std::string name);
		};
	}
}

#endif /* CPP_BABEL_2018_PAGEMANAGER_HPP */
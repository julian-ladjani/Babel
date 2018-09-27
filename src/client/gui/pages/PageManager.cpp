//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// PageManager.cpp
//

#include "PageManager.hpp"


int babel::client::PageManager::addWidget(ABabelPage *w, std::string name)
{
	_names[name] = w;
	return QStackedWidget::addWidget(w);
}

babel::client::ABabelPage *babel::client::PageManager::getPage(std::string name)
{
	return _names.at(name);
}

void babel::client::PageManager::setCurrentPage(std::string name)
{
	QStackedWidget::setCurrentWidget(getPage(name));
}

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** WidgetManager.cpp
*/

#include "WidgetManager.hpp"

babel::client::WidgetManager::WidgetManager()
{
    _list.clear();
}

babel::client::WidgetManager::~WidgetManager()
{
}

const std::map<std::string, QWidget *> &babel::client::WidgetManager::get_list() const {
    return _list;
}

void babel::client::WidgetManager::set_list(const std::map<std::string, QWidget *> &_list) {
    WidgetManager::_list = _list;
}

void babel::client::WidgetManager::addWidget(QWidget *widget, std::string name) {
    _list[name] = widget;

}

QWidget *babel::client::WidgetManager::getWidget(std::string name) {
    if ( _list.find(name) == _list.end() ) {
        std::cout << "Widget not exist\n";
    } else {
        return _list.at(name);
    }
}

babel::client::Button *babel::client::WidgetManager::getButton(std::string name) {
    if ( _list.find(name) == _list.end() ) {
        std::cout << "Widget not exist\n";
    } else {
        return (Button *)_list.at(name);
    }
}

void babel::client::WidgetManager::setVisible(bool view) {
    for (std::map<std::string, QWidget *>::iterator it=_list.begin(); it!=_list.end(); ++it)
        it->second->setVisible(view);
}

void babel::client::WidgetManager::addInLayout(QBoxLayout *layout, Qt::AlignmentFlag position) {
    for (std::map<std::string, QWidget *>::iterator it=_list.begin(); it!=_list.end(); ++it)
        layout->addWidget(it->second, 0, position);
}

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** WidgetManager.hpp
*/

#ifndef WIDGETMANAGER_HPP_
#define WIDGETMANAGER_HPP_


#include <string>
#include <QtWidgets/QWidget>
#include <iostream>
#include <QtWidgets/QBoxLayout>
#include "Button.hpp"

namespace babel {
    namespace client {
	class WidgetManager {
	public:
	    WidgetManager();

	    ~WidgetManager();

	    const std::map<std::string, QWidget *> &get_list() const;
	    void set_list(const std::map<std::string, QWidget *> &_list);
	    void addWidget(QWidget *widget, std::string name);

	    QWidget *getWidget(std::string);
	    babel::client::Button *getButton(std::string);
	    void setVisible(bool view);

	    void addInLayout(QBoxLayout *layout, Qt::AlignmentFlag position);

	protected:
	    std::map<std::string, QWidget *> _list;

	private:
	};
    }
}
#endif /* !WIDGETMANAGER_HPP_ */

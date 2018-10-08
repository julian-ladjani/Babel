/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ListWidget.hpp
*/

#ifndef LISTWIDGET_HPP_
#define LISTWIDGET_HPP_

#include <QObject>
#include <QtWidgets/QListWidget>
#include <QKeyEvent>
#include <src/common/User.hpp>

namespace babel {
    namespace client {
	class ListWidget : public QListWidget {
	Q_OBJECT
	public:
	    ListWidget(DragDropMode mode);
	    ~ListWidget();
	    void addContacts(std::vector<common::User> contacts);
	    void keyPressEvent(QKeyEvent *event);
	    void removePersonne();
	protected:
	private:
	};
    }
}

#endif /* !LISTWIDGET_HPP_ */

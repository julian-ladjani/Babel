/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ListWidget.hpp
*/

#ifndef LISTWIDGET_HPP_
#define LISTWIDGET_HPP_

#include <QtWidgets/QListWidget>
#include <QKeyEvent>

namespace babel {
    namespace client {
	class ListWidget : public QListWidget {
	public:
	    ListWidget(DragDropMode mode);

	    ~ListWidget();

	    void AddPersonne();
	    void keyPressEvent(QKeyEvent *event);
	    void removePersonne();

	protected:
	private:
	};
    }
}

#endif /* !LISTWIDGET_HPP_ */

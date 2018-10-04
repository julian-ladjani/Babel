/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ListWidget.cpp
*/

#include <iostream>
#include "ListWidget.hpp"

babel::client::ListWidget::ListWidget(DragDropMode mode)
{
    setDragDropMode(mode);
    setWrapping(false);
    setStyleSheet("background-color:#3d3d3d;color: #f04c00;");
}



babel::client::ListWidget::~ListWidget()
{

}

void babel::client::ListWidget::AddPersonne(std::vector<common::User> contacts) {
    for (uint32_t i = 0; i < contacts.size(); i++){
        QListWidgetItem *itm = new QListWidgetItem;
        if (contacts[i].getLogin().length() > 32)
            itm->setText(QString::fromStdString
            (contacts[i].getLogin()).left(29)+"...");
        else
            itm->setText(QString::fromStdString(contacts[i].getLogin()));
        if (contacts[i].isConnected())
            itm->setIcon(QIcon("src/assets/img/off.png"));
        else
            itm->setIcon(QIcon("src/assets/img/on.png"));
        itm->setSizeHint(QSize(50,50));
        addItem(itm);
        itm->setTextAlignment(Qt::AlignCenter);
    }
}

void babel::client::ListWidget::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete)
        removePersonne();

}

void babel::client::ListWidget::removePersonne() {
    if (currentItem() && dragDropMode() == QAbstractItemView::DropOnly)
        delete currentItem();
}

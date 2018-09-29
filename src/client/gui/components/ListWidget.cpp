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
    for (int i=0; i < contacts.size(); i++){
        QListWidgetItem *itm = new QListWidgetItem;
        itm->setText(QString::fromStdString(contacts[i].getLogin()));
        if (contacts[i].isConnected())
            itm->setIcon(QIcon("src/assets/img/off.png"));
        else
            itm->setIcon(QIcon("src/assets/img/on.png"));
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
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
    for (auto &contact : contacts) {
        auto *itm = new QListWidgetItem;
        if (contact.getLogin().length() > 32)
            itm->setText(QString::fromStdString
            (contact.getLogin()).left(29)+"...");
        else
            itm->setText(QString::fromStdString(contact.getLogin()));
        itm->setIcon(QIcon((contact.isConnected()) ?
                "src/assets/img/off.png" : "src/assets/img/on.png"));
        itm->setSizeHint(QSize(50,50));
        itm->setData(Qt::UserRole, contact.getId());
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

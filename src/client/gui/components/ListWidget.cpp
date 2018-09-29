/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ListWidget.cpp
*/

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

void babel::client::ListWidget::AddPersonne() {
    for (int i=0; i!=20; i++){
        QListWidgetItem *itm = new QListWidgetItem;
        itm->setText("Benoit 16");
        itm->setIcon(QIcon("src/assets/img/off.png"));
        itm->setSizeHint(QSize(50, 50));
        addItem(itm);
        itm->setTextAlignment(Qt::AlignCenter);

    }
}

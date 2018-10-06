/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** GroupeBox.hpp
*/

#ifndef GROUPEBOX_HPP_
#define GROUPEBOX_HPP_

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QBoxLayout>
#include <vector>

namespace babel {
    namespace client {
	class GroupBox : public QGroupBox {
	public:
	    GroupBox(QBoxLayout *layout = new QVBoxLayout);

	    ~GroupBox();

	    QWidget *addWidget(QWidget *widget);

	protected:
	private:
	    	QBoxLayout *_layout;
		std::vector<QWidget *> _list;
	};
    }
}

#endif /* !GROUPEBOX_HPP_ */

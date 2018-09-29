/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Label.hpp
*/

#ifndef LABEL_HPP_
#define LABEL_HPP_

#include <QtWidgets/QLabel>
namespace babel {
    namespace client {
	class Label : public QLabel {
	public:
	    Label(QString text);

	    ~Label();

	protected:
	private:
	};
    }
}

#endif /* !LABEL_HPP_ */

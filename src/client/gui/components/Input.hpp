/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Input.hpp
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <QtWidgets/QLineEdit>

namespace babel {
	namespace client {
		class Input : public QLineEdit
		{
			public:
			Input(int size, QString placeholder);

			Input(QString placeholders);

			~Input();
		};
	}
}

#endif /* !INPUT_HPP_ */

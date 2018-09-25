/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** CButton.hpp
*/

#include "Button.hpp"

#ifndef CBUTTON_HPP_
#define CBUTTON_HPP_


namespace babel {
	namespace client {

class CButton : public Button
{
	public:
		CButton(const QString &text, const QString style, int size = 70);
		~CButton();

	protected:
	private:
};

	}
}

#endif /* !BUTTON_HPP_ */

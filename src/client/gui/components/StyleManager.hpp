/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** StyleManager.hpp
*/

#ifndef STYLEMANAGER_HPP_
#define STYLEMANAGER_HPP_

#include <array>
#include <memory>
#include "Style.hpp"

namespace babel {
    namespace client {
	class StyleManager {
	public:
		StyleManager(int size = 0);

		enum Sheet{
		REDBUTTON,
		GREENBUTTON,
		ORANGEBUTTON,
		DEFAULTBUTTON,
		HYPERTEXTBUTTON
	    };
	    StyleManager();
	    ~StyleManager();
	    QString getSheet(Sheet sheet);


	protected:
	private:
	    	std::array<std::unique_ptr<QString>, 5> _styles;
		QString createRedButton(int size);
		QString createGreenButton(int size);
		QString createOrangeButton(int size);
		QString createDefaultButton(int size);
		QString createHyperTextButton(int size);
	};
    }
}
#endif /* !STYLEMANAGER_HPP_ */

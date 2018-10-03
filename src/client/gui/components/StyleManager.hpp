/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** StyleManager.hpp
*/

#ifndef STYLEMANAGER_HPP_
#define STYLEMANAGER_HPP_

#include "Style.hpp"
#include <memory>
namespace babel {
    namespace client {
	class StyleManager {
	public:
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
		QString createRedButton();
		QString createGreenButton();
		QString createOrangeButton();
		QString createDefaultButton();
		QString createHyperTextButton();
	};
    }
}
#endif /* !STYLEMANAGER_HPP_ */

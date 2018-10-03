/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Style.hpp
*/

#ifndef STYLE_HPP_
#define STYLE_HPP_

#include <QtCore/QString>
#include <vector>
#include "StyleManager.hpp"

namespace babel {
    namespace client {
	class Style {
	public:
	    Style(QString type, QString mode = "");
	    ~Style();
	    void setWidth(int size);
	    void setHeight(int size);
	    void setBackground(QString color);
	    void setColor(QString color);
	    void setFont(QString fond);
	    void setBorder(QString border, int radius);
	    void setExtra(QString extra);
	    QString getStyleStreet() const;
	protected:
	private:
	    	std::vector<QString> _styleSheet;
	};
    }
}

#endif /* !STYLE_HPP_ */

/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Image.hpp
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <QPixmap>
#include <QtWidgets/QLabel>

namespace babel {
    namespace client {
	class Image : public QLabel {
	public:
	    Image(const QString text, int size);
	    ~Image();
	};
    }
}
#endif /* !IMAGE_HPP_ */

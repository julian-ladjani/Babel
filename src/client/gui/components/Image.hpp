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
#include <fstream>
#include <src/common/exception/Exception.hpp>


namespace babel {
    namespace client {
	class Image : public QLabel {
	public:
	    Image(const QString text, int size);
	    ~Image();
	    void update(const QString text, int size);
	};
    }
}
#endif /* !IMAGE_HPP_ */

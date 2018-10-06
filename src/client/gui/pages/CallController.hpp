//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// CallController.hpp
//

#ifndef CPP_BABEL_2018_CALLCONTROLLER_HPP
#define CPP_BABEL_2018_CALLCONTROLLER_HPP

#include <QtCore/QObject>

namespace babel {
	namespace client {
		class CallController : public QObject
		{
		Q_OBJECT
		public:
			CallController();
			int startCall();

			void yaduson(std::vector<unsigned short> l);
		Q_SIGNALS:
			void sound(std::vector<unsigned short> l);
		};

	}
}

#endif /* CPP_BABEL_2018_CALLCONTROLLER_HPP */
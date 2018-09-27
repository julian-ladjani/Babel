/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ABabelPage.hpp
*/

#ifndef CPP_BABEL_2018_IBABELPAGE_HPP
#define CPP_BABEL_2018_IBABELPAGE_HPP

#include <QWidget>
#include <QObject>
#include <src/client/ClientInfo.hpp>

namespace babel {
	namespace client {
		class ABabelPage : public QWidget {
		Q_OBJECT
		public:
			ABabelPage (ClientInfo &_infos) :
				QWidget(), _infos(_infos) {};
			virtual ~ABabelPage() {}
		protected:
			ClientInfo &_infos;
		};
	}
}

#endif /* CPP_BABEL_2018_IBABELPAGE_HPP */
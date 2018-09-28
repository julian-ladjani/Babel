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
#include <QtWidgets/QGridLayout>

namespace babel {
	namespace client {
		class ABabelPage : public QWidget {
		Q_OBJECT
		public:
			ABabelPage(ClientInfo &_infos);
			~ABabelPage() override {}
		protected:
			virtual void connections() = 0;
			ClientInfo &_infos;
			QGridLayout *_layout;
		};
	}
}

#endif /* CPP_BABEL_2018_IBABELPAGE_HPP */
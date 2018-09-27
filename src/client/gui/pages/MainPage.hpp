//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainPage.hpp
//

#ifndef CPP_BABEL_2018_MAINPAGE_HPP
#define CPP_BABEL_2018_MAINPAGE_HPP

#include <src/client/ClientInfo.hpp>
#include "ABabelPage.hpp"

namespace babel {
	namespace client {
		class MainPage : public ABabelPage
		{
		public:
			explicit MainPage(client::ClientInfo &_infos);
		};

	}
}


#endif /* CPP_BABEL_2018_MAINPAGE_HPP */
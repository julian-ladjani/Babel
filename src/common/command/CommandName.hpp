/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** CommandName.hpp
*/

#ifndef CPP_BABEL_2018_COMMANDNAME_HPP
#define CPP_BABEL_2018_COMMANDNAME_HPP

namespace babel {
	namespace common {
		enum CommandName {
			UNDEFINED = 0,
			LOGIN,
			LOGOUT,
			USER,		//id, username
			CONNECT,	//id, ip?
			DISCONNECT,	//id
			CALL,		//id, ip?, port
			CALL_ANSWER	//id, answer
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDNAME_HPP

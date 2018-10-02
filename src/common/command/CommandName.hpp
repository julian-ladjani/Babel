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
			CMD_ERROR,
			OK,
			LOGIN,
			LOGIN_OK,
			LOGOUT,
			DELETE,
			USER,
			USER_STATE,
			CALL,
			CALL_ANSWER,
			CALL_END,
			ADD_CONTACT,
			MESSAGE
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDNAME_HPP

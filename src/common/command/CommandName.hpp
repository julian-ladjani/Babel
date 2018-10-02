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
			CMD_UNDEFINED = 0,
			CMD_ERROR,
			CMD_OK,
			CMD_LOGIN,
			CMD_LOGIN_OK,
			CMD_LOGOUT,
			CMD_DELETE,
			CMD_USER,
			CMD_USER_STATE,
			CMD_CALL,
			CMD_CALL_ANSWER,
			CMD_CALL_END,
			CMD_ADD_CONTACT,
			CMD_MESSAGE
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDNAME_HPP

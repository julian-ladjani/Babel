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
			ERROR,		//dit au client qu'il y a eu une erreur (message)
			LOGIN,		//permet a un client de se connecter (username, password)
			LOGIN_OK,	//dit au client qu'il c'est bien connecter ou inscrit (id, username)
			LOGOUT,		//permet a un client de se déconnecter (void)
			DELETE,		//permet de supprimer son compte (void)
			USER,		//dit au client que cet user existe (id, username, state)
			CONNECT,	//dit au client que le user c'est connecter (id)
			DISCONNECT,	//dit au client que le user c'est déconnecter (id)
			CALL,		//permet d'appeler un client OU de recevoir un appelle (id, ip, port)
			CALL_ANSWER,	//permet de repondre a un appel (id, ip, port)
			CALL_END,	//permet de savoir que l'appel c'est terminer avec le user (id)
			ADD_CONTACT,	//permet d'ajouter un contact OU de savoir que le user est un contact (id)
			MESSAGE,	//envoie un message au user OU dit au user qu'il a recu un message (id, message)
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDNAME_HPP

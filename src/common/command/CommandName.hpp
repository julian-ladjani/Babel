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
			ERROR,		//dit au client qu'il y a eu une erreur avec la commande (commandID, message)
			OK,		//dit au client que la commande a reussi (commandID, message)
			LOGIN,		//permet a un client de se connecter (username, password)
			LOGIN_OK,	//dit au client qu'il c'est bien connecter ou inscrit (id, username)
			LOGOUT,		//permet a un client de se déconnecter (void)
			DELETE,		//permet de supprimer son compte (void)
			USER,		//dit au client que cet user existe (id, username, state)
			USER_STATE,	//dit au client l'etat du user (id, state)
			CALL,		//permet d'appeler un client OU de recevoir un appel (id, ip, port)
			CALL_ANSWER,	//permet de repondre a un appel (id, ip, port)
			CALL_END,	//permet de savoir que l'appel c'est terminer avec le user OU de terminer un appel avec le user (id)
			ADD_CONTACT,	//permet d'ajouter un contact OU de savoir que le user est un contact (id)
			MESSAGE,	//envoie un message au user OU dit au user qu'il a recu un message (id, message)
		};
	}
}

#endif //CPP_BABEL_2018_COMMANDNAME_HPP

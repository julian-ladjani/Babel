/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** ClientInfo.cpp
*/

#ifndef CPP_BABEL_2018_CLIENTINFOS_HPP
#define CPP_BABEL_2018_CLIENTINFOS_HPP

#include <vector>
#include <algorithm>
#include <src/client/network/QtTcpSocket.hpp>
#include "src/common/User.hpp"

namespace babel {
	namespace client {
		class ClientInfo : public QObject{
		Q_OBJECT
		public:
			ClientInfo();
			common::User &getClientInfo();
			void setClientInfo(const common::User &clientInfo);
			const common::ConnectionInfo &getServerInfo() const;
			void setServerInfo(
				const common::ConnectionInfo &serverInfo);
			const std::vector<common::User> &getContacts() const;
			void setContacts(
				const std::vector<common::User> &contacts);
			void addContact(common::User user);
			void removeContact(common::User user);
			QtTcpSocket &getSocket();
			common::User &getActiveUser();
			void setActiveUser(common::User &activeUser);
			common::User &getContact(uint32_t id);
		Q_SIGNALS:
			void userUpdated();
		private:
			common::User _clientInfo;
			common::ConnectionInfo _serverInfo;
			std::vector<common::User> _contacts;
			QtTcpSocket _socket;
			uint32_t _activeUserId;
		};
	}
}

#endif //CPP_BABEL_2018_CLIENTINFOS_HPP

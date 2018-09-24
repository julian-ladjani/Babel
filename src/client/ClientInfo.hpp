//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - ClientInfos.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_BABEL_2018_CLIENTINFOS_HPP
#define CPP_BABEL_2018_CLIENTINFOS_HPP

#include <vector>
#include <algorithm>
#include <src/common/User.hpp>

namespace babel {
	namespace client {
		class ClientInfo {
		public:
			ClientInfo();
			const common::User &getClientInfo() const;
			void setClientInfo(const common::User &clientInfo);
			const common::ConnectionInfo &getServerInfo() const;
			void setServerInfo(
				const common::ConnectionInfo &serverInfo);
			const std::vector<common::User> &getContacts() const;
			void setContacts(
				const std::vector<common::User> &contacts);
			void addContact(common::User user);
			void removeContact(common::User user);

		private:
			common::User _clientInfo;
			common::ConnectionInfo _serverInfo;
			std::vector<common::User> _contacts;
		};
	}
}


#endif //CPP_BABEL_2018_CLIENTINFOS_HPP

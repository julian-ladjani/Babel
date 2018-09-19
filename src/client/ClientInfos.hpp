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
		class ClientInfos {
		public:
			ClientInfos();
			const common::User &getClientInfos() const;
			void setClientInfos(const common::User &clientInfos);
			const common::ConnectionInfos &getServerInfos() const;
			void setServerInfos(
				const common::ConnectionInfos &serverInfos);
			const std::vector<common::User> &getContacts() const;
			void setContacts(
				const std::vector<common::User> &contacts);
			void addContact(common::User user);
			void removeContact(common::User user);

		private:
			common::User _clientInfos;
			common::ConnectionInfos _serverInfos;
			std::vector<common::User> _contacts;
		};
	}
}


#endif //CPP_BABEL_2018_CLIENTINFOS_HPP

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	TcpServerException class
*/

#ifndef CPP_BABEL_2018_TCPSERVEREXCEPTION_HPP
#define CPP_BABEL_2018_TCPSERVEREXCEPTION_HPP

#include "src/common/exception/Exception.hpp"

namespace babel
{
	namespace server
	{
		class TcpServerException : public common::Exception {
		public:
			explicit TcpServerException(
				const std::string &message = "Unknown Error");
		};
	}
}
#endif //CPP_BABEL_2018_TCPSERVEREXCEPTION_HPP

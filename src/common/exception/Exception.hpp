/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Exception.hpp
*/

#ifndef CPP_INDIE_STUDIO_EXCEPTION_HPP
#define CPP_INDIE_STUDIO_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace babel {
	namespace common {
		class Exception : public std::exception {
		public:
			explicit Exception(
				const std::string &context = "Undefined",
				const std::string &message = "Unknown Error");
			const char *what() const noexcept override;

		private:
			std::string _what;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_EXCEPTION_HPP */

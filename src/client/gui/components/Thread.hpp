/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Thread.hpp
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <QtCore/QThread>
namespace babel {
    namespace client {
	class Thread : public QThread {
	public:
	    explicit Thread();

	    ~Thread();

	    void run();
	    void out();

	protected:
	private:
	    bool _test;
	};
    }
}
#endif /* !THREAD_HPP_ */

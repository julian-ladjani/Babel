/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** TMicro.hpp
*/

#ifndef TMicro_HPP_
#define TMicro_HPP_

#include <QtCore/QThread>
#include <src/client/sound/AudioEncoder.hpp>
#include <src/client/sound/AudioManager.hpp>
#include <src/client/gui/pages/MainPage.hpp>
namespace babel {
    namespace client {
	class TMicro : public QThread {
	public:
	    TMicro(ABabelPage *page);
	    ~TMicro();

	    void run();
	    void changeMic();

	    bool is_loop() const;

	private:
	    bool _loop;
	    AudioManager audio;
	};
    }
}
#endif /* !TMicro_HPP_ */

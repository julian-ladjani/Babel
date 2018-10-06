/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** TConversation.hpp
*/

#ifndef TConversation_HPP_
#define TConversation_HPP_

#include <QtCore/QThread>
#include <src/client/sound/AudioEncoder.hpp>
#include <src/client/sound/AudioManager.hpp>
#include <src/client/gui/pages/MainPage.hpp>
namespace babel {
    namespace client {
	class TConversation : public QThread {
	public:
	    TConversation(ABabelPage *page);
	    virtual ~TConversation(){};
	    void run();
	    void applyConversation();
	    bool is_loop() const;
	    void changeContact(QString address, int port);

	private:
	    bool _loop;
	    AudioManager _audio;
	    AudioEncoder _encoder;
	    QUdpSocket _udpSocket;
	    QString _address;
	    int _port;
	};
    }
}
#endif /* !TConversation_HPP_ */
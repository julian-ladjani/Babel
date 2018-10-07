/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** TConversation.cpp
*/

#include "TConversation.hpp"

babel::client::TConversation::TConversation(ABabelPage *page):
	_loop(false),_audio(), _encoder(_audio.getSampleRate(), _audio.getChannel()),
	_udpSocket(page),_address(""), _port(53876)
{
    QObject::connect((ConnectionPage *)page,
    	&ConnectionPage::applyConversation, this,
    	&TConversation::applyConversation);
}

void babel::client::TConversation::run()
{
    _audio.startStream();
   _audio.startRecording();
    while (_loop) {
	std::vector<uint16_t> voice(_encoder.encode(_audio.getRecord()));
	_udpSocket.writeDatagram(
		QByteArray(QByteArray((char *)voice.data(), (int)(voice.size() * 2))),
		 QHostAddress(_address),
		 (quint16)_port);
    }
    _audio.stopRecording();
    _audio.closeStream();
}

void babel::client::TConversation::applyConversation(){
	_loop = !_loop;
	if (_loop)
	    start();
}



bool babel::client::TConversation::is_loop() const
{
    return _loop;
}

void babel::client::TConversation::changeContact(QString address, int port) {
    _address = address;
    _port = port;
}

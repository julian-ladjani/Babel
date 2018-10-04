/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** TMicro.cpp
*/

#include "TMicro.hpp"

babel::client::TMicro::TMicro(ABabelPage *page): _loop(false)
{
    QObject::connect((MainPage *)page, &MainPage::changeMic, this, &TMicro::changeMic);
}

babel::client::TMicro::~TMicro()
{
}

void babel::client::TMicro::run()
{
	babel::client::AudioManager audio;
	babel::client::AudioEncoder encoder(audio.getSampleRate(),
					    audio.getChannel());
	audio.startStream();
	audio.startRecording();
	while (_loop) {
		audio.playRecord(encoder.decode(
			encoder.encode(audio.getRecord())));
	}
}

void babel::client::TMicro::changeMic()
{
	_loop = !_loop;
	if (_loop)
	    start();
}

bool babel::client::TMicro::is_loop() const
{
    return _loop;
}

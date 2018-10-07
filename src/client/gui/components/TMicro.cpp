/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** TMicro.cpp
*/

#include "TMicro.hpp"

babel::client::TMicro::TMicro(ABabelPage *page): _loop(false), _audio(),
	_encode(_audio.getSampleRate(), _audio.getChannel())
{
    QObject::connect((MainPage *)page, &MainPage::changeMic, this, &TMicro::changeMic);
}

babel::client::TMicro::~TMicro()
{
}

void babel::client::TMicro::run()
{
	_audio.startStream();
	_audio.startRecording();
	while (_loop) {
		_audio.playRecord(_encode.decode(_encode.encode(_audio.getRecord())));
	}
	_audio.stopRecording();
	_audio.closeStream();
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

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** Thread.cpp
*/

#include <src/client/sound/AudioEncoder.hpp>
#include <src/client/sound/AudioManager.hpp>
#include "Thread.hpp"

babel::client::Thread::Thread(): _test(true)
{
}

babel::client::Thread::~Thread()
{
}

void babel::client::Thread::run()
{
	babel::client::AudioManager audio;
	babel::client::AudioEncoder encoder(audio.getSampleRate(),
					    audio.getChannel());
	audio.startStream();
	audio.startRecording();
	while (_test) {
		audio.playRecord(encoder.decode(
			encoder.encode(audio.getRecord())));
	}
}

void babel::client::Thread::out()
{
	_test = !_test;
}

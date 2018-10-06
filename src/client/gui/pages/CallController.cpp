//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// CallController.cpp
//

#include <src/client/sound/AudioManager.hpp>
#include <src/client/sound/AudioEncoder.hpp>
#include "CallController.hpp"

babel::client::CallController::CallController()
{
}

int babel::client::CallController::startCall()
{
	babel::client::AudioManager audio;
	babel::client::AudioEncoder encoder(audio.getSampleRate(), audio.getChannel());
	audio.startStream();
	audio.startRecording();
	auto lol = encoder.encode(audio.getRecord());
	emit CallController::sound(lol);
	return 0;
}

void babel::client::CallController::yaduson(std::vector<unsigned short> l)
{
	printf("son\n");
}
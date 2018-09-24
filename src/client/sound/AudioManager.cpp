/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#include "AudioManager.hpp"

babel::client::AudioManager::AudioManager() :
	_recording(false), _playing(false), _streaming(false),
	_playingSound(false), _volume(50)
{
	PaError paErr = Pa_Initialize();
	if (paErr != paNoError)
		throwPortAudioError(paErr);
}

babel::client::AudioManager::~AudioManager()
{
	PaError paErr;
	if (_recording)
		stopRecording();
	if (_streaming)
		stopStream();
	paErr = Pa_Terminate();
	if (paErr != paNoError)
		throwPortAudioError(paErr);
}


void babel::client::AudioManager::startStream()
{
	PaError paErr = Pa_OpenDefaultStream(
		&_stream, 2, 2, paInt16, 48000, 480, nullptr, nullptr);
	if (paErr != paNoError)
		throwPortAudioError(paErr);
	_streaming = true;
}

void babel::client::AudioManager::stopStream()
{
	PaError paErr = Pa_CloseStream(_stream);
	if (paErr != paNoError)
		throwPortAudioError(paErr);
	_streaming = false;
}

void babel::client::AudioManager::startRecording()
{
	PaError paErr = Pa_StartStream(_stream);
	if (paErr != paNoError)
		throwPortAudioError(paErr);
	_recording = true;
}

void babel::client::AudioManager::stopRecording()
{
	PaError paErr = Pa_StopStream(_stream);
	if (paErr != paNoError)
		throwPortAudioError(paErr);
	_recording = false;
}

unsigned int babel::client::AudioManager::getVolume() const
{
	return _volume;
}

void babel::client::AudioManager::setVolume(unsigned int volume)
{
	_volume = volume;
}

void babel::client::AudioManager::throwPortAudioError(PaError paErr)
{
	std::string message(std::string("Error PortAudio: ")
			    + Pa_GetErrorText(paErr) + "\n");
	throw std::logic_error(message);
}
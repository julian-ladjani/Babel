/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#include "AudioManager.hpp"

babel::client::AudioManager::AudioManager() :
	_recording(false), _playing(false), _streaming(false),
	_playingSound(false), _volume(50), _channel(2),
	_bufferSize(1024), _sampleRate(25000), _stream(nullptr)
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

std::vector<unsigned short> babel::client::AudioManager::getRecord() const
{
	std::vector<unsigned short> record(_bufferSize * _channel);
	while (Pa_GetStreamReadAvailable(_stream) < _bufferSize);
	PaError paErr = Pa_ReadStream(_stream, record.data(),
				      _bufferSize);
	if (paErr != paNoError)
		throwPortAudioError(paErr);
	return record;
}

void babel::client::AudioManager::playRecord(
	std::vector<unsigned short> record) const
{
	PaError paErr = Pa_WriteStream(_stream, record.data(), record.size());
	if (paErr != paNoError)
		throwPortAudioError(paErr);
}

void babel::client::AudioManager::startStream()
{
	PaError paErr = Pa_OpenDefaultStream(
		&_stream, _channel, _channel, paInt16, _sampleRate,
		_bufferSize, nullptr, nullptr);
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

unsigned int babel::client::AudioManager::getChannel() const
{
	return _channel;
}

void babel::client::AudioManager::setChannel(unsigned int channel)
{
	_channel = channel;
}

unsigned int babel::client::AudioManager::getBufferSize() const
{
	return _bufferSize;
}

void babel::client::AudioManager::setBufferSize(unsigned int bufferSize)
{
	_bufferSize = bufferSize;
}

unsigned int babel::client::AudioManager::getSampleRate() const
{
	return _sampleRate;
}

void babel::client::AudioManager::setSampleRate(unsigned int sampleRate)
{
	_sampleRate = sampleRate;
}

void babel::client::AudioManager::throwPortAudioError(PaError paErr) const
{
	std::string message(std::string("Error PortAudio: ")
			    + Pa_GetErrorText(paErr) + "\n");
	throw std::logic_error(message);
}
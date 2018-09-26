/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#include "AudioManager.hpp"

babel::client::AudioManager::AudioManager() :
	_recording(false), _playing(false), _streaming(false),
	_bufferSize(480), _channel(1), _sampleRate(48000), _stream(nullptr)
{
	PaError paErr = Pa_Initialize();
	if (paErr != paNoError)
		throwPortAudioError(paErr);
}

babel::client::AudioManager::~AudioManager()
{
	PaError paErr;
	closeStream();
	paErr = Pa_Terminate();
	if (paErr != paNoError)
		throwPortAudioError(paErr);
}

std::vector<unsigned short> babel::client::AudioManager::getRecord()
{
	PaError paErr;
	std::vector<unsigned short> record(_bufferSize);
	if (Pa_GetStreamReadAvailable(_stream) < _bufferSize)
		paErr = Pa_ReadStream(
			_stream, record.data(),
			(unsigned long)Pa_GetStreamReadAvailable(_stream));
	else
		paErr = Pa_ReadStream(_stream, record.data(), _bufferSize);
	if (paErr != paNoError)
		restartStream();
	return record;
}

void babel::client::AudioManager::playRecord(
	std::vector<unsigned short> record)
{
	PaError paErr;
	while (Pa_GetStreamWriteAvailable(_stream) < record.size());
	paErr = Pa_WriteStream(_stream, record.data(),
			       record.size());
	if (paErr != paNoError)
		restartStream();
}

void babel::client::AudioManager::restartStream()
{
	closeStream();
	startStream();
	startRecording();
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

void babel::client::AudioManager::closeStream()
{
	if (_recording)
		stopRecording();
	if (_streaming)
		stopStream();
}

uint32_t babel::client::AudioManager::getChannel() const
{
	return _channel;
}

void babel::client::AudioManager::setChannel(uint32_t channel)
{
	_channel = channel;
}

uint32_t babel::client::AudioManager::getBufferSize() const
{
	return _bufferSize;
}

void babel::client::AudioManager::setBufferSize(uint32_t bufferSize)
{
	_bufferSize = bufferSize;
}

uint32_t babel::client::AudioManager::getSampleRate() const
{
	return _sampleRate;
}

void babel::client::AudioManager::setSampleRate(uint32_t sampleRate)
{
	_sampleRate = sampleRate;
}

void babel::client::AudioManager::throwPortAudioError(PaError paErr) const
{
	throw babel::common::Exception("PortAudio Error", Pa_GetErrorText(paErr));
}
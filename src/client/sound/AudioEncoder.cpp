//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - AudioEncoder.cpp
// File description:
// Created by Gregory EPLE
//

#include "AudioEncoder.hpp"

babel::client::AudioEncoder::AudioEncoder(unsigned int sampleRate,
					  unsigned int channel) :
	_encoder(nullptr), _decoder(nullptr)
{
	int opusErr;
	_encoder = opus_encoder_create(
		sampleRate, channel, OPUS_APPLICATION_AUDIO, &opusErr);
	if (opusErr != OPUS_OK)
		throw std::logic_error("Opus Error: Cannot create encoder");
	_decoder = opus_decoder_create(sampleRate, channel, &opusErr);
	if (opusErr != OPUS_OK)
		throw std::logic_error("Opus Error: Cannot create decoder");
}

babel::client::AudioEncoder::~AudioEncoder()
{
	if (_encoder)
		opus_encoder_destroy(_encoder);
	if (_decoder)
		opus_decoder_destroy(_decoder);
}

std::vector<unsigned short>
babel::client::AudioEncoder::decode(std::vector<unsigned short> encoded)
{
	std::vector<unsigned short> decoded(encoded.size());
	int bytes = opus_decode(_decoder,
				(unsigned char *)encoded.data(),
				(int)encoded.size(),
				(opus_int16 *)decoded.data(),
				(int)encoded.size(), 0);
	return decoded;
}

std::vector<unsigned short>
babel::client::AudioEncoder::encode(std::vector<unsigned short> sample)
{
	std::vector<unsigned short> encoded(sample.size());
	int bytes = opus_encode(_encoder,
				(opus_int16 const *)sample.data(),
				(int)sample.size(),
				(unsigned char *)(encoded.data()),
				(int)encoded.size());
	return encoded;
}

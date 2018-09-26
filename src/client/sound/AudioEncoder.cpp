/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** AudioEncoder.cpp
*/

#include <src/common/exception/Exception.hpp>
#include "AudioEncoder.hpp"

babel::client::AudioEncoder::AudioEncoder(uint32_t sampleRate,
					  uint32_t channel) :
	_encoder(nullptr), _decoder(nullptr)
{
	int opusErr;
	_encoder = opus_encoder_create(
		sampleRate, channel, OPUS_APPLICATION_VOIP, &opusErr);
	if (opusErr != OPUS_OK)
		throwOpusError(opusErr);
	_decoder = opus_decoder_create(sampleRate, channel, &opusErr);
	if (opusErr != OPUS_OK)
		throwOpusError(opusErr);
}

babel::client::AudioEncoder::~AudioEncoder()
{
	if (_encoder)
		opus_encoder_destroy(_encoder);
	if (_decoder)
		opus_decoder_destroy(_decoder);
}

std::vector<unsigned short>
babel::client::AudioEncoder::decode(std::vector<unsigned short> encoded) const
{
	std::vector<unsigned short> decoded(encoded.size());
	int bytes = opus_decode(_decoder,
				(unsigned char *)encoded.data(),
				(int)encoded.size(),
				(opus_int16 *)decoded.data(),
				(int)encoded.size(), 0);
	if (bytes < 0)
		throwOpusError(OPUS_INVALID_PACKET);
	return decoded;
}

std::vector<unsigned short>
babel::client::AudioEncoder::encode(std::vector<unsigned short> sample) const
{
	std::vector<unsigned short> encoded(sample.size());
	int bytes = opus_encode(_encoder,
				(opus_int16 const *)sample.data(),
				(int)sample.size(),
				(unsigned char *)(encoded.data()),
				(int)encoded.size());
	if (bytes < 0)
		throwOpusError(OPUS_INVALID_PACKET);
	return encoded;
}

void babel::client::AudioEncoder::throwOpusError(int opusErr) const
{
	throw babel::common::Exception("Opus Error", opus_strerror(opusErr));
}
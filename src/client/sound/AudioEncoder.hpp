/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** AudioEncoder.hpp
*/

#ifndef CPP_BABEL_2018_AUDIOENCODER_HPP
#define CPP_BABEL_2018_AUDIOENCODER_HPP

#include <opus/opus.h>
#include <vector>
#include <string>
#include <src/common/exception/Exception.hpp>

namespace babel {
	namespace client {
		class AudioEncoder {
		public:
			AudioEncoder(uint32_t sampleRate,
				     uint32_t channel);
			virtual ~AudioEncoder();
			std::vector<uint16_t> decode(
				std::vector<uint16_t> encoded) const;
			std::vector<uint16_t> encode(
				std::vector<uint16_t> sample) const;

		private:
			OpusEncoder *_encoder;
			OpusDecoder *_decoder;
			void throwOpusError() const;
		};
	}
}


#endif //CPP_BABEL_2018_AUDIOENCODER_HPP

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** AudioEncoder.hpp
*/

#ifndef CPP_BABEL_2018_AUDIOENCODER_HPP
#define CPP_BABEL_2018_AUDIOENCODER_HPP

#include <stdexcept>
#include <opus/opus.h>
#include <vector>
#include <string>

namespace babel {
	namespace client {
		class AudioEncoder {
		public:
			AudioEncoder(uint32_t sampleRate,
				     uint32_t channel);
			virtual ~AudioEncoder();
			std::vector<unsigned short> decode(
				std::vector<unsigned short> encoded) const;
			std::vector<unsigned short> encode(
				std::vector<unsigned short> sample) const;

		private:
			OpusEncoder *_encoder;
			OpusDecoder *_decoder;
			void throwOpusError(int opusErr) const;
		};
	}
}


#endif //CPP_BABEL_2018_AUDIOENCODER_HPP

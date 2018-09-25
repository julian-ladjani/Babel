//
// EPITECH PROJECT, 2018
// CPP_babel_2018 - AudioEncoder.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_BABEL_2018_AUDIOENCODER_HPP
#define CPP_BABEL_2018_AUDIOENCODER_HPP

#include <stdexcept>
#include <opus/opus.h>
#include <vector>

namespace babel {
	namespace client {
		class AudioEncoder {
		public:
			AudioEncoder(unsigned int sampleRate,
				     unsigned int channel);
			virtual ~AudioEncoder();
			std::vector<unsigned short> decode(
				std::vector<unsigned short> encoded);
			std::vector<unsigned short> encode(
				std::vector<unsigned short> sample);

		private:
			OpusEncoder *_encoder;
			OpusDecoder *_decoder;
		};
	}
}


#endif //CPP_BABEL_2018_AUDIOENCODER_HPP

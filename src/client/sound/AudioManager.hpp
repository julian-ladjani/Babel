/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#ifndef CPP_BABEL_2018_AUDIOMANAGER_HPP
#define CPP_BABEL_2018_AUDIOMANAGER_HPP

#include <portaudio.h>
#include <string>
#include <vector>
#include <src/common/exception/Exception.hpp>

namespace babel
{
	namespace client
	{
		class AudioManager {
		public:
			AudioManager();
			virtual ~AudioManager();
			std::vector<unsigned short> getRecord();
			void playRecord(
				std::vector<unsigned short> record);
			void restartStream();
			void startStream();
			void stopStream();
			void startRecording();
			void stopRecording();
			void closeStream();
			uint32_t getChannel() const;
			void setChannel(uint32_t channel);
			uint32_t getBufferSize() const;
			void setBufferSize(uint32_t bufferSize);
			uint32_t getSampleRate() const;
			void setSampleRate(uint32_t sampleRate);

		private:
			bool _recording;
			bool _streaming;
			bool _playing;
			uint32_t _channel;
			uint32_t _bufferSize;
			uint32_t _sampleRate;
			PaStream *_stream;
			void throwPortAudioError(PaError paErr) const;
		};
	}
}

#endif //CPP_BABEL_2018_AUDIOMANAGER_HPP

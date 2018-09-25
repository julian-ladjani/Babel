/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#ifndef CPP_BABEL_2018_AUDIOMANAGER_HPP
#define CPP_BABEL_2018_AUDIOMANAGER_HPP

#include <portaudio.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace babel
{
	namespace client
	{
		class AudioManager {
		public:
			AudioManager();
			virtual ~AudioManager();
			std::vector<unsigned short> getRecord() const;
			void playRecord(
				std::vector<unsigned short> record) const;
			void startStream();
			void stopStream();
			void startRecording();
			void stopRecording();
			void startPlaying();
			void stopPlaying();
			unsigned int getVolume() const;
			void setVolume(unsigned int volume);
			unsigned int getChannel() const;
			void setChannel(unsigned int channel);
			unsigned int getBufferSize() const;
			void setBufferSize(unsigned int bufferSize);
			unsigned int getSampleRate() const;
			void setSampleRate(unsigned int sampleRate);

		private:
			bool _recording;
			bool _streaming;
			bool _playing;
			bool _playingSound;
			unsigned int _volume;
			unsigned int _channel;
			unsigned int _bufferSize;
			unsigned int _sampleRate;
			PaStream *_stream;
			void throwPortAudioError(PaError paErr) const;
		};
	}
}

#endif //CPP_BABEL_2018_AUDIOMANAGER_HPP

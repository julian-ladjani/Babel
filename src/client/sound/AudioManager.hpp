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

namespace babel
{
	namespace client
	{
		class AudioManager {
		public:
			AudioManager();
			virtual ~AudioManager();
			void playSound();
			void startStream();
			void stopStream();
			void startRecording();
			void stopRecording();
			void startPlaying();
			void stopPlaying();
			unsigned int getVolume() const;
			void setVolume(unsigned int _volume);

		private:
			bool _recording;
			bool _streaming;
			bool _playing;
			bool _playingSound;
			unsigned int _volume;
			PaStream *_stream = nullptr;
			void throwPortAudioError(PaError paErr);
		};
	}
}

#endif //CPP_BABEL_2018_AUDIOMANAGER_HPP

/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#ifndef CPP_BABEL_2018_AUDIOMANAGER_HPP
#define CPP_BABEL_2018_AUDIOMANAGER_HPP

//#include <portaudio.h>

namespace babel
{
	namespace common
	{
		class AudioManager {
		public:
			AudioManager();
			bool playSound();
			bool startRecording();
			bool stopRecording();
			bool startPlaying();
			bool stopPlaying();
			unsigned int getVolume() const;
			void setVolume(unsigned int volume);
		private:
			bool isRecording;
			bool isPlaying;
			bool isPlayingSound;
			unsigned int volume;
		};
	}
}

#endif //CPP_BABEL_2018_AUDIOMANAGER_HPP

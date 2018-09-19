/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** 	AudioManager class
*/

#include "AudioManager.hpp"

unsigned int babel::common::AudioManager::getVolume() const
{
	return volume;
}

void babel::common::AudioManager::setVolume(unsigned int volume)
{
	AudioManager::volume = volume;
}

babel::common::AudioManager::AudioManager() : isRecording(false),
	isPlaying(false), isPlayingSound(false), volume(50)
{

}

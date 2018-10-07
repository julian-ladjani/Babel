/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** soundPacket.hpp
*/

#ifndef CPP_BABEL_2018_SOUNDPACKET_HPP
#define CPP_BABEL_2018_SOUNDPACKET_HPP

#include <cstdint>

struct SoundPacket {
	int magicNumber;
	unsigned long size;
	int64_t timeStamp;
	char sound[960];
};

union SoundPacketConvertor {
	SoundPacket sp;
	char buf[976];
};

#endif /* CPP_BABEL_2018_SOUNDPACKET_HPP */
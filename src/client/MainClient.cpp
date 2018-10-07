/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** MainClient.cpp
*/

#include <iostream>
#include <QtGui>
#include <QtWidgets>
#include <QPalette>
#include <QApplication>
#include <src/common/exception/Exception.hpp>
#include <src/client/sound/AudioManager.hpp>
#include <src/client/sound/AudioEncoder.hpp>
#include <src/client/gui/MainWindow.hpp>
#include <src/client/network/soundPacket.hpp>

std::vector<uint16_t> convert(SoundPacket sp)
{
	std::vector<uint16_t> tmp;
	for (unsigned int i = 0; i < sp.size; i += 2) {
		tmp.push_back((uint16_t)(sp.sound[i] + (sp.sound[i + 1] << 8)));
	}
	return tmp;
}

int main(int argc, char *argv[])
{
	babel::client::AudioManager _audio;
	_audio.startStream();
	_audio.startRecording();
/*	while (1) {
		SoundPacket sp;
		SoundPacketConvertor spConv;
		std::vector<uint16_t> voice(_audio.getRecord());
		sp.size = voice.size() * 2;
		sp.magicNumber = 0x666;
		sp.timeStamp = QDateTime::currentDateTime().toTime_t();
		std::memset(sp.sound, 0, sp.size);
		memcpy(sp.sound, voice.data(), sp.size);
		spConv.sp = sp;
		QByteArray qba(spConv.buf, 976);
		SoundPacketConvertor spc;
		std::memset(spc.sp.sound, 0, 960);
		memcpy(spc.buf, qba.data(), 976);
		write(1, spc.sp.sound, 960);
		putchar('\n');
		std::vector<uint16_t> bufferToCompress = convert(spc.sp);
		_audio.playRecord(bufferToCompress);
	}*/
	try {
	    	QFontDatabase::removeAllApplicationFonts();
		QApplication a(argc, argv);
	    	int font = QFontDatabase::addApplicationFont("src/assets/font/DejaVuSans.ttf");
	    	QApplication::setFont(QFontDatabase::systemFont((QFontDatabase::SystemFont)font));
		babel::client::MainWindow w;
		w.show();

		return a.exec();
	} catch (babel::common::Exception &e) {
		std::cout << e.what() << std::endl;
		return 84;
	}
}
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
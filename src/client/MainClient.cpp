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

int main(int argc, char *argv[])
{
	try {
/*	babel::client::AudioManager audio;
		babel::client::AudioEncoder encoder(audio.getSampleRate(), audio.getChannel());
		audio.startStream();
		audio.startRecording();
		for (;;) {
			audio.playRecord(encoder.decode(encoder.encode(audio.getRecord())));
		}*/

		QApplication a(argc, argv);
		babel::client::MainWindow w;
		w.show();

		return a.exec();
	} catch (babel::common::Exception &e) {
		std::cout << e.what() << std::endl;
		return 84;
	}
}
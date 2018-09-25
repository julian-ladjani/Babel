//
// EPITECH PROJECT, 2018
// CPP_babel_2018
// File description:
// MainClient.hpp
//

#include <iostream>
#include <QtGui>
#include <QtWidgets>
#include <QPalette>
#include <QApplication>
#include "./windows/Window.hpp"

#include <src/client/sound/AudioManager.hpp>
#include <src/client/sound/AudioEncoder.hpp>

int main(int argc, char *argv[])
{
/*	babel::client::AudioManager audio;
//	babel::client::AudioEncoder encoder(audio.getSampleRate(), audio.getChannel());
	audio.startStream();
	audio.startRecording();
	for (;;) {
//		audio.playRecord(encoder.decode(encoder.encode(audio.getRecord())));
		audio.playRecord(audio.getRecord());
	}*/

	QApplication a(argc, argv);
	babel::client::MainWindow w;
	w.show();

	return a.exec();
}
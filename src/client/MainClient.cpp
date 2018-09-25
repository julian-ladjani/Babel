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

int main(int argc, char *argv[])
{
/*	babel::client::AudioManager audio;
	audio.startStream();
	audio.startRecording();
	while (1) {
		audio.playRecord(audio.getRecord());
	}*/

	QApplication a(argc, argv);
	babel::client::MainWindow w;
	w.show();

	return a.exec();
}
/*
** EPITECH PROJECT, 2018
** CPP_babel_2018
** File description:
** StyleManager.cpp
*/

#include "StyleManager.hpp"

babel::client::StyleManager::StyleManager(int size)
	: _styles({std::make_unique<QString>(createRedButton(size)),
		   std::make_unique<QString>(createGreenButton(size)),
		   std::make_unique<QString>(createOrangeButton(size)),
		   std::make_unique<QString>(createDefaultButton(size)),
		   std::make_unique<QString>(createHyperTextButton(size)),})
{

}

babel::client::StyleManager::~StyleManager()
{
}

QString babel::client::StyleManager::createRedButton(int size) {
	Style main("QPushButton");
	main.setBackground("#ed1b24");
	main.setFont("bold 30px");
    	Style press("QPushButton", ":pressed");
    	press.setBackground("#cd1b24");
    	Style focus("QPushButton", ":focus");
    	focus.setExtra("outline: 0");
    	return main.getStyleStreet() +
    		press.getStyleStreet() + focus.getStyleStreet();
}

QString babel::client::StyleManager::createGreenButton(int size) {
    Style main("QPushButton");
    main.setBackground("#3ab54a");
    main.setFont("bold 30px");
    Style press("QPushButton", ":pressed");
    press.setBackground("#0ab54a");
    Style focus("QPushButton", ":focus");
    focus.setExtra("outline: 0");
    return main.getStyleStreet() +
	   press.getStyleStreet() + focus.getStyleStreet();
}

QString babel::client::StyleManager::createOrangeButton(int size) {
    Style main("QPushButton");
    main.setBackground("#f04c00");
    main.setFont("bold 15px");
    main.setBorder("none", 0);
    Style press("QPushButton", ":pressed");
    press.setBackground("#d34200");
    Style focus("QPushButton", ":focus");
    focus.setExtra("outline: 0");
    return main.getStyleStreet() +
	   press.getStyleStreet() + focus.getStyleStreet();
}

QString babel::client::StyleManager::createDefaultButton(int size) {
    Style main("QPushButton");
    main.setBackground("#f04c00");
    main.setBorder("none", size);
    main.setFont("bold 15px");
    Style press("QPushButton", ":pressed");
    press.setBackground("#d34200");
    Style focus("QPushButton", ":focus");
    focus.setExtra("outline: 0");
    return main.getStyleStreet() +
	   press.getStyleStreet() + focus.getStyleStreet();
}

QString babel::client::StyleManager::createHyperTextButton(int size) {
    Style main("QPushButton");
    main.setBackground("#3d3d3d");
    main.setBorder("none", size);
    main.setFont("bold 15px");
    main.setColor("#f04c00");
    Style focus("QPushButton", ":focus");
    focus.setExtra("outline: 0");
    return main.getStyleStreet() +
	    focus.getStyleStreet();
}

QString babel::client::StyleManager::getSheet(Sheet sheet) {
    return *_styles[sheet].get();
}

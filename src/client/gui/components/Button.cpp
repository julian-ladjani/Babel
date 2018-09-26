/*
** EPITECH PROJECT, 2018
** CPP_Babel_2018
** File description:
** Button.cpp
*/

#include "Button.hpp"

babel::client::Button::Button(const QString &text, const QString style, Size size) : _ishover(false), _event(nullptr)
{
	setMouseTracking(true);
    	setAttribute(Qt::WA_Hover);
	std::ifstream infile;
	std::string utf8_text = text.toUtf8().constData();
	infile.open(utf8_text, std::ios::in);
	if (infile)
		setIcon(QIcon(text));
	else
		setText(text);
	setIconSize(QSize(size.getY()/1.3, size.getY()/1.3));
	auto stylewidth = QStringLiteral("QPushButton {"
			"min-width:%1px;"
			"max-width:%1px;}").arg(size.getX());
	auto styleheight =QStringLiteral("QPushButton {"
			"min-height:%1px;"
			"max-height:%1px;}").arg(size.getY());
	setStyleSheet(style+stylewidth+styleheight);
	setEnabled(true);
}

babel::client::Button::~Button()
{
}

void babel::client::Button::setFunction(std::function<void()> event)
{
	_event = event;
}

void babel::client::Button::hoverEnter(QHoverEvent *)
{
    std::cout << _ishover <<"\n";
    _ishover = true;
}

void babel::client::Button::hoverLeave(QHoverEvent *)
{
    _ishover = false;
    std::cout << _ishover <<"\n";
}

void babel::client::Button::hoverMove(QHoverEvent *)
{
    std::cout << _ishover <<"\n";
}

void babel::client::Button::hoverClick(QHoverEvent *)
{
		std::cout << "LIL1\n";
	if (_ishover == true && _event != nullptr){
		std::cout << "LIL\n";
		_event();
	}
}

bool babel::client::Button::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::MouseButtonPress:
	hoverClick(static_cast<QHoverEvent*>(event));
	break;
    default:
        break;
    }
    return QWidget::event(event);
}
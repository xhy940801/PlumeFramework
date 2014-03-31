#include "PlumeButton.h"

using namespace Plume;


PlumeButton::PlumeButton(void) :
unclickedStyle(Color(242, 242, 242), Color(235, 235, 235),
	Color(221, 221, 221), Color(207, 207, 207), Color(60, 127, 177), Color(251, 251, 251)),
	moveOnStyle(Color(236, 246, 253), Color(217, 240, 252),
	Color(190, 230, 253), Color(167, 217, 245), Color(60, 127, 177), Color(251, 251, 251)),
	clickedStyle(Color(229, 244, 252), Color(196, 229, 246),
	Color(152, 209, 239), Color(104, 179, 219), Color(44, 98, 139), Color(195, 195, 195)),
	currentStyle(&unclickedStyle),
	text(0)
{
}


PlumeButton::~PlumeButton(void)
{
}


void PlumeButton::draw(PlumeGraphics* graphics)
{
	graphics->setBrush(currentStyle->brushOne);
	graphics->drawRectangleFi(posRect.left + 2, posRect.top + 2, posRect.right - posRect.left - 4, (posRect.bottom - posRect.top - 4) / 2);

	graphics->setBrush(currentStyle->brushTwo);
	graphics->drawRectangleFi(posRect.left + 2, (posRect.top + posRect.bottom) / 2, posRect.right - posRect.left - 4, (posRect.bottom - posRect.top - 3) / 2);
}


bool PlumeButton::leftButtonDown(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &clickedStyle;
//		this->frame->flush();
//		this->frame->setCapture();
		return true;
	}
	return false;
}


bool PlumeButton::leftButtonUp(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &moveOnStyle;
//		this->frame->flush();
		return true;
	}
	else
	{
		currentStyle = &unclickedStyle;
//		this->frame->flush();
	}
//	this->frame->releaseCapture();
	return false;
}


bool PlumeButton::rightButtonDown(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &clickedStyle;
//		this->frame->flush();
//		this->frame->setCapture();
		return true;
	}
	return false;
}


bool PlumeButton::rightButtonUp(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &moveOnStyle;
	//	this->frame->flush();
		return true;
	}
	else
	{
		currentStyle = &unclickedStyle;
//		this->frame->flush();
	}
//	this->frame->releaseCapture();
	return false;
}


bool PlumeButton::middleButtonDown(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &clickedStyle;
//		this->frame->flush();
//		this->frame->setCapture();
		return true;
	}
	return false;
}


bool PlumeButton::middleButtonUp(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &moveOnStyle;
	//	this->frame->flush();
		return true;
	}
	else
	{
		currentStyle = &unclickedStyle;
	//	this->frame->flush();
	}
//	this->frame->releaseCapture();
	return false;
}


bool PlumeButton::mouseMove(int px, int py, KeyCondition condition)
{
	if(!(condition & (MouseCondition::LeftButtonDown | MouseCondition::RightButtonDown | MouseCondition::MiddleButtonDown)))
	{
		if(this->isInRect(px, py))
		{
			currentStyle = &moveOnStyle;
	//		this->frame->setCapture();
		}
		else
		{
			currentStyle = &unclickedStyle;
	//		this->frame->releaseCapture();
		}
	//	this->frame->flush();
	}
	else
	{
		if(currentStyle == &unclickedStyle && this->isInRect(px, py))
		{
			currentStyle = &moveOnStyle;
	//		this->frame->setCapture();
	//		this->frame->flush();
		}
		else if(currentStyle == &moveOnStyle && !this->isInRect(px, py))
		{
			currentStyle = &unclickedStyle;
		//	this->frame->releaseCapture();
		//	this->frame->flush();
		}
	}
	return false;
}

void PlumeButton::setText(ConstStr pstr)
{
	this->text = pstr;
}

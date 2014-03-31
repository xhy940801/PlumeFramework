#include "PlumeButton.h"

using namespace Plume;


PlumeButton::PlumeButton(void) :
unclickedStyle(PlumeColor(242, 242, 242), PlumeColor(235, 235, 235),
	PlumeColor(221, 221, 221), PlumeColor(207, 207, 207), PlumeColor(60, 127, 177), PlumeColor(251, 251, 251)),
	moveOnStyle(PlumeColor(236, 246, 253), PlumeColor(217, 240, 252),
	PlumeColor(190, 230, 253), PlumeColor(167, 217, 245), PlumeColor(60, 127, 177), PlumeColor(251, 251, 251)),
	clickedStyle(PlumeColor(229, 244, 252), PlumeColor(196, 229, 246),
	PlumeColor(152, 209, 239), PlumeColor(104, 179, 219), PlumeColor(44, 98, 139), PlumeColor(195, 195, 195)),
	currentStyle(&unclickedStyle),
	text(0)
{
}


PlumeButton::~PlumeButton(void)
{
}


void PlumeButton::draw(PlumeGraphics* graphics)
{
	graphics->fillRectangleWithLinearGradient(currentStyle->colorTop, currentStyle->colorMiddle1, posRect.left,posRect.top, posRect.right - posRect.left, (posRect.bottom - posRect.top) / 2 + 1, PlumeGraphics::Vertical);
	graphics->fillRectangleWithLinearGradient(currentStyle->colorMiddle2, currentStyle->colorBottom, posRect.left, (posRect.bottom + posRect.top) / 2, posRect.right - posRect.left, (posRect.bottom - posRect.top) / 2, PlumeGraphics::Vertical);
	graphics->drawUnCornerRectangle(currentStyle->colorFrame2, 1, posRect.left + 1, posRect.top + 1, posRect.right - 2, posRect.bottom - 2, 1);
	graphics->drawUnCornerRectangle(currentStyle->colorFrame1, 1, posRect.left, posRect.top, posRect.right - 1, posRect.bottom - 1, 1);
	graphics->drawCorner(currentStyle->colorFrame2, posRect.left + 2, posRect.top + 2,  posRect.right - 3, posRect.bottom - 3);
	graphics->drawCorner(currentStyle->colorFrame1, posRect.left + 1, posRect.top + 1,  posRect.right - 2, posRect.bottom - 2);
	graphics->drawText(text, PlumeColor::Black, posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top, PlumeGraphics::StringAlignment::StringAlignmentCenter);

}


bool PlumeButton::leftButtonDown(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &clickedStyle;
		this->frame->flush();
		this->frame->setCapture();
		return true;
	}
	return false;
}


bool PlumeButton::leftButtonUp(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &moveOnStyle;
		this->frame->flush();
		return true;
	}
	else
	{
		currentStyle = &unclickedStyle;
		this->frame->flush();
	}
	this->frame->releaseCapture();
	return false;
}


bool PlumeButton::rightButtonDown(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &clickedStyle;
		this->frame->flush();
		this->frame->setCapture();
		return true;
	}
	return false;
}


bool PlumeButton::rightButtonUp(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &moveOnStyle;
		this->frame->flush();
		return true;
	}
	else
	{
		currentStyle = &unclickedStyle;
		this->frame->flush();
	}
	this->frame->releaseCapture();
	return false;
}


bool PlumeButton::middleButtonDown(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &clickedStyle;
		this->frame->flush();
		this->frame->setCapture();
		return true;
	}
	return false;
}


bool PlumeButton::middleButtonUp(int px, int py, KeyCondition condition)
{
	if(this->isInRect(px, py))
	{
		currentStyle = &moveOnStyle;
		this->frame->flush();
		return true;
	}
	else
	{
		currentStyle = &unclickedStyle;
		this->frame->flush();
	}
	this->frame->releaseCapture();
	return false;
}


bool PlumeButton::mouseMove(int px, int py, KeyCondition condition)
{
	if(!(condition & (MouseCondition::LeftButtonDown | MouseCondition::RightButtonDown | MouseCondition::MiddleButtonDown)))
	{
		if(this->isInRect(px, py))
		{
			currentStyle = &moveOnStyle;
			this->frame->setCapture();
		}
		else
		{
			currentStyle = &unclickedStyle;
			this->frame->releaseCapture();
		}
		this->frame->flush();
	}
	else
	{
		if(currentStyle == &unclickedStyle && this->isInRect(px, py))
		{
			currentStyle = &moveOnStyle;
			this->frame->setCapture();
			this->frame->flush();
		}
		else if(currentStyle == &moveOnStyle && !this->isInRect(px, py))
		{
			currentStyle = &unclickedStyle;
			this->frame->releaseCapture();
			this->frame->flush();
		}
	}
	return false;
}

void PlumeButton::setText(ConstStr pstr)
{
	this->text = pstr;
}

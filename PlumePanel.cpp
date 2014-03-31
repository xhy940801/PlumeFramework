#include "PlumePanel.h"

using namespace Plume;


PlumePanel::PlumePanel(void)
	: backgroundImage(0), backgroundColor(Gdiplus::Color::White), frameType(0), frameWidth(1), otherFrameInfo(3)
{
	layout = &PlumeLayout::defaultLayout;
}


PlumePanel::~PlumePanel(void)
{
}


void PlumePanel::draw(PlumeGraphics* graphics)
{
	if(backgroundImage)
	{
		graphics->drawImage(*backgroundImage, posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
	}
	else
	{
		graphics->fillRectangle(backgroundColor, posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
	}
	if(frameType)
	{
		switch(frameType & 0x0000ffff)
		{
		case SOLID:
			graphics->setLineStyle(PlumeGraphics::LineStyle::DashStyleSolid);
			break;
		case DASH:
			graphics->setLineStyle(PlumeGraphics::LineStyle::DashStyleDash);
			break;
		case DOT:
			graphics->setLineStyle(PlumeGraphics::LineStyle::DashStyleDot);
			break;
		case DASHDOT:
			graphics->setLineStyle(PlumeGraphics::LineStyle::DashStyleDashDot);
			break;
		case DASHDOTDOT:
			graphics->setLineStyle(PlumeGraphics::LineStyle::DashStyleDashDotDot);
			break;
		}
		Rect insertRect = posRect;
		graphics->getInnerRect(insertRect, frameWidth);
		switch(frameType & 0xffff0000)
		{
		case RECTANGLE:
			graphics->drawRectangle(frameColor, this->frameWidth, insertRect.left, insertRect.top, insertRect.right - insertRect.left, insertRect.bottom - insertRect.top);
			break;
		case ELLIPSE:
			graphics->drawEllipse(frameColor, this->frameWidth, insertRect.left, insertRect.top, insertRect.right - insertRect.left, insertRect.bottom - insertRect.top);
			break;
		case ROUNDEDRECTANGLE:
			graphics->drawRoundedRectangle(frameColor, this->frameWidth, insertRect.left, insertRect.top, insertRect.right, insertRect.bottom, this->otherFrameInfo);
			break;
		}
	}
	for(int i=0;i<components.size();++i)
		components[i]->draw(graphics);
}


void PlumePanel::changePosRect(const Rect& rect)
{
	posRect = rect;
	layout->flushClientRect(&posRect);
}


void PlumePanel::changePosRect(const int left, const int top, const int right, const int bottom)
{
	posRect.left = left;
	posRect.top = top;
	posRect.right = right;
	posRect.bottom = bottom;
	layout->flushClientRect(&posRect);
}


bool PlumePanel::leftButtonDown(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->leftButtonDown(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::leftButtonUp(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->leftButtonUp(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::leftButtonDoubleClick(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->leftButtonDoubleClick(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::rightButtonDown(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->rightButtonDown(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::rightButtonUp(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->rightButtonUp(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::rightButtonDoubleClick(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->rightButtonDoubleClick(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::middleButtonDown(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->middleButtonDown(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::middleButtonUp(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->middleButtonUp(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::middleButtonDoubleClick(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->middleButtonDoubleClick(px, py, condition))
			return true;
	}
	return false;
}


bool PlumePanel::keyDown(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->keyDown(vkCode, keyInfo))
			return true;
	}
	return false;
}


bool PlumePanel::systemKeyDown(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->systemKeyDown(vkCode, keyInfo))
			return true;
	}
	return false;
}


bool PlumePanel::keyUp(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->keyUp(vkCode, keyInfo))
			return true;
	}
	return false;
}


bool PlumePanel::systemKeyUp(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->systemKeyUp(vkCode, keyInfo))
			return true;
	}
	return false;
}

void PlumePanel::setBackgroundColor(Gdiplus::Color* color)
{
	backgroundColor = *color;
	backgroundImage = 0;
}


int PlumePanel::addComponent(PlumeComponent* component)
{
	components.push_back(component);
	layout->addComponent(component);
	component->setFrame(this->frame);
	return components.size() - 1;
}


PlumeComponent* PlumePanel::deleteComponent(unsigned int n)
{
#ifdef _DEBUG
	if(n < 0 || n >= components.size())
	{
		return 0;
	}
#endif
	PlumeComponent* p = components[n];
	components[n] = components[components.size() - 1];
	components.pop_back();
	layout->deleteComponent(p);
	return p;
}


void PlumePanel::setLayout(PlumeLayout* PlumeLayout)
{
	layout = PlumeLayout;
	for(unsigned int i=0;i<components.size();++i)
		layout->addComponent(components[i]);
}


void PlumePanel::setFrame(unsigned int type, unsigned int width,const PlumeColor* color, unsigned int otherInfo)
{
	this->frameWidth = width;
	this->frameType = type;
	this->otherFrameInfo = otherInfo;
	this->frameColor = *color;
}
//
//void Plume::PlumePanel::drawRoundedRectangle(Gdiplus::Graphics* graphics, const Rect& rect, unsigned char width)
//{
//	graphics->DrawLine(framePen, rect.left + width - 1, rect.top, rect.right - width + 1, rect.top);
//	graphics->DrawArc(framePen, rect.right - width * 2, rect.top, width * 2, width * 2, 270, 90);
//
//	graphics->DrawLine(framePen, rect.right, rect.top + width - 1, rect.right, rect.bottom - width + 1);
//	graphics->DrawArc(framePen, rect.right - 2 * width, rect.bottom - 2 * width, width * 2, width * 2, 0, 90);
//
//	graphics->DrawLine(framePen, rect.right - width + 1, rect.bottom, rect.left + width - 1, rect.bottom);
//	graphics->DrawArc(framePen, rect.left, rect.bottom - 2 * width, width * 2, width * 2, 90, 90);
//
//	graphics->DrawLine(framePen, rect.left, rect.bottom - width + 1, rect.left, rect.top + width - 1);
//	graphics->DrawArc(framePen, rect.left, rect.top, width * 2, width * 2, 180, 90);
//}


 void PlumePanel::setFrame(PlumeFrame* f)
 {
	 this->frame = f;
	 for(int i=0;i<components.size();++i)
		 components[i]->setFrame(f);
 }


 bool PlumePanel::mouseMove(int px, int py, KeyCondition condition)
 {
	 for(unsigned int i=0;i<components.size();++i)
	 {
		 if(components[i]->mouseMove(px, py, condition))
			 return true;
	 }
	 return false;
 }
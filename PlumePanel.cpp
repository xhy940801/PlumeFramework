#include "PlumePanel.h"

using namespace Plume;


PlumePanel::PlumePanel(void)
	: backgroundColor(Color::White), frameLineStyle(Pen::SOLID), frameStyle(DEFAULT), frameWidth(1), frameXRadius(3), frameYRadius(3)
{
	layout = &PlumeLayout::defaultLayout;
	initPanel();
}


PlumePanel::~PlumePanel(void)
{
}


void PlumePanel::initPanel()
{
	if(frameStyle != DEFAULT)
	{
		framePen.setStyle(frameLineStyle);
	}
}


void PlumePanel::draw(PlumeGraphics* graphics)
{
	graphics->setBrush(backgroundBrush);
	graphics->setPen(framePen);
	graphics->drawRectangleFi(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
	switch(frameStyle)
	{
	case DEFAULT:
		break;
	case RECTANGLE:
		graphics->drawRectangleFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
		break;
	case ELLIPSE:
		graphics->drawEllipseFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
		break;
	case ROUNDRECTANGLE:
		graphics->drawRoundRectangleFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top, frameXRadius, frameYRadius);
		break;
	default:
		break;
	}
	Point oldOffset;
	graphics->setOffsetEx(posRect.left, posRect.top, oldOffset);
	for(unsigned int i=0;i<components.size();++i)
		components[i]->draw(graphics);
	graphics->setOffset(oldOffset);
}


void PlumePanel::changePosRect(const Rect& rect)
{
	posRect = rect;
	layout->flushContainerSize(posRect.right - posRect.left, posRect.bottom - posRect.top);
}


void PlumePanel::changePosRect(const int left, const int top, const int right, const int bottom)
{
	posRect.left = left;
	posRect.top = top;
	posRect.right = right;
	posRect.bottom = bottom;
	layout->flushContainerSize(right - left, bottom - top);
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
}


int PlumePanel::addComponent(PlumeComponent* component)
{
	components.push_back(component);
	layout->addComponent(component);
	component->setContainer(this);
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


void PlumePanel::setFrame(Pen::PenStyle lineStyle, FrameStyle style, unsigned int width, const Color& color, int xRadius, int yRadius)
{
	this->frameWidth = width;
	this->frameLineStyle = lineStyle;
	this->frameStyle = style;
	this->frameXRadius = xRadius;
	this->frameYRadius = yRadius;
	this->frameColor = color;

	this->framePen.setStatus(frameColor, lineStyle, frameWidth, Pen::INSIDEFRAME);
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


bool PlumePanel::mouseMove(int px, int py, KeyCondition condition)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->mouseMove(px, py, condition))
			return true;
	}
	return false;
}


void PlumePanel::setBackgroundColor(const Color& color)
{
	this->backgroundBrush.setColor(color);
}


void PlumePanel::flush(const Rect& rect)
{
	Rect newRect;
	newRect.left = rect.left + posRect.left;
	newRect.top = rect.top + posRect.top;
	newRect.right = rect.right + posRect.left;
	newRect.bottom = rect.bottom + posRect.top;
	this->container->flush(newRect);
}
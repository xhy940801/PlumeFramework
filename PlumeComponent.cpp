#include "PlumeComponent.h"

using namespace Plume;

PlumeComponent::PlumeComponent(void)
{
}


PlumeComponent::~PlumeComponent(void)
{
}


bool PlumeComponent::isInRect(int px, int py)
{
	return px >= posRect.left && px < posRect.right && py < posRect.bottom && py >= posRect.top;
}


void PlumeComponent::draw(PlumeGraphics* graphics)
{
}


void PlumeComponent::changePosRect(const Rect& rect)
{
	posRect = rect;
}


void PlumeComponent::changePosRect(const int left, const int top, const int right, const int bottom)
{
	posRect.left = left;
	posRect.top = top;
	posRect.right = right;
	posRect.bottom = bottom;
}


bool PlumeComponent::leftButtonDown(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::leftButtonUp(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::leftButtonDoubleClick(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::rightButtonDown(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::rightButtonUp(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::rightButtonDoubleClick(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::middleButtonDown(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::middleButtonUp(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::middleButtonDoubleClick(int px, int py, KeyCondition condition)
{
	return false;
}


bool PlumeComponent::keyDown(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	return false;
}


bool PlumeComponent::systemKeyDown(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	return false;
}


bool PlumeComponent::keyUp(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	return false;
}


bool PlumeComponent::systemKeyUp(VirtualKeyCode vkCode, KeyInfo keyInfo)
{
	return false;
}


bool PlumeComponent::mouseMove(int px, int py, KeyCondition condition)
{
	return false;
}


void PlumeComponent::setFrame(PlumeFrame* f)
{
	frame = f;
}
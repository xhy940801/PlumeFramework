#pragma once
#ifndef _PLUME_PLUMECOMPONENT_H_
#define _PLUME_PLUMECOMPONENT_H_
#include <Windows.h>
#include <GdiPlus.h>

#include "PlumeTypeDefine.h"
#include "PlumeGraphics.h"
#include "PlumeFrame.h"


namespace Plume
{
	class PlumeFrame;
	class PlumeComponent
	{
	protected:
		Rect posRect;
		PlumeFrame* frame;
	public:
		PlumeComponent(void);
		~PlumeComponent(void);
		virtual void setFrame(PlumeFrame* f);
		bool isInRect(int px, int py);

		virtual void draw(PlumeGraphics* graphics);
		virtual void changePosRect(const Rect& rect);
		virtual void changePosRect(const int left, const int top, const int right, const int bottom);

		virtual bool leftButtonDown(int px, int py, KeyCondition condition);
		virtual bool leftButtonUp(int px, int py, KeyCondition condition);
		virtual bool leftButtonDoubleClick(int px, int py, KeyCondition condition);

		virtual bool rightButtonDown(int px, int py, KeyCondition condition);
		virtual bool rightButtonUp(int px, int py, KeyCondition condition);
		virtual bool rightButtonDoubleClick(int px, int py, KeyCondition condition);

		virtual bool middleButtonDown(int px, int py, KeyCondition condition);
		virtual bool middleButtonUp(int px, int py, KeyCondition condition);
		virtual bool middleButtonDoubleClick(int px, int py, KeyCondition condition);

		virtual bool keyDown(VirtualKeyCode vkCode, KeyInfo keyInfo);
		virtual bool keyUp(VirtualKeyCode vkCode, KeyInfo keyInfo);
		virtual bool systemKeyDown(VirtualKeyCode vkCode, KeyInfo keyInfo);
		virtual bool systemKeyUp(VirtualKeyCode vkCode, KeyInfo keyInfo);

		virtual bool mouseMove(int px, int py, KeyCondition condition);
	};

}

#endif
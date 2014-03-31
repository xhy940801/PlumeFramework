#pragma once
#ifndef _PLUME_PLUMEPANEL_H_
#define _PLUME_PLUMEPANEL_H_

#include "PlumeComponent.h"
#include "PlumeTypeDefine.h"
#include "PlumeLayout.h"

#include <vector>

namespace Plume
{

	class PlumePanel :
		public Plume::PlumeComponent
	{
	protected:
		PlumeColor backgroundColor;
		PlumeImage* backgroundImage;

		unsigned int frameType;
		unsigned int frameWidth;
		unsigned int otherFrameInfo;
		PlumeColor frameColor;

		std::vector<PlumeComponent*> components;
		PlumeLayout *layout;
	public:
		PlumePanel(void);
		~PlumePanel(void);

		void draw(PlumeGraphics* graphics);

		void changePosRect(const Rect& rect);
		void changePosRect(const int left, const int top, const int right, const int bottom);

		bool leftButtonDown(int px, int py, KeyCondition condition);
		bool leftButtonUp(int px, int py, KeyCondition condition);
		bool leftButtonDoubleClick(int px, int py, KeyCondition condition);

		bool rightButtonDown(int px, int py, KeyCondition condition);
		bool rightButtonUp(int px, int py, KeyCondition condition);
		bool rightButtonDoubleClick(int px, int py, KeyCondition condition);

		bool middleButtonDown(int px, int py, KeyCondition condition);
		bool middleButtonUp(int px, int py, KeyCondition condition);
		bool middleButtonDoubleClick(int px, int py, KeyCondition condition);

		bool keyDown(VirtualKeyCode vkCode, KeyInfo keyInfo);
		bool keyUp(VirtualKeyCode vkCode, KeyInfo keyInfo);
		bool systemKeyDown(VirtualKeyCode vkCode, KeyInfo keyInfo);
		bool systemKeyUp(VirtualKeyCode vkCode, KeyInfo keyInfo);

		bool mouseMove(int px, int py, KeyCondition condition);
		void setBackgroundColor(Gdiplus::Color* color);


		int addComponent(PlumeComponent* component);
		PlumeComponent* deleteComponent(unsigned int n);
		void setLayout(PlumeLayout* PlumeLayout);
		void setFrame(unsigned int type, unsigned int width,const Gdiplus::Color* color, unsigned int otherInfo = 3);
	//	void drawRoundedRectangle(Gdiplus::Graphics* graphics, const Rect& rect, unsigned char width);

		 void setFrame(PlumeFrame* f);

	public:
		static const unsigned int DEFAULT = 0x00000000;

		static const unsigned int SOLID = 0x00000001;
		static const unsigned int DASH = 0x00000002;
		static const unsigned int DOT = 0x00000003;
		static const unsigned int DASHDOT = 0x00000004;
		static const unsigned int DASHDOTDOT = 0x00000005;

		static const unsigned int RECTANGLE = 0x00010000;
		static const unsigned int ELLIPSE = 0x00020000;
		static const unsigned int ROUNDEDRECTANGLE = 0x00030000;
	};

}

#endif
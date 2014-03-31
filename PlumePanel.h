#pragma once
#ifndef _PLUME_PLUMEPANEL_H_
#define _PLUME_PLUMEPANEL_H_

#include "PlumeComponent.h"
#include "PlumeTypeDefine.h"
#include "PlumeLayout.h"
#include "PlumeContainer.h"

#include <vector>

namespace Plume
{

	class PlumePanel :
		public Plume::PlumeComponent, public Plume::PlumeContainer
	{
	public:
		enum FrameStyle
		{
			DEFAULT, RECTANGLE, ELLIPSE, ROUNDRECTANGLE
		};
	protected:
		Color backgroundColor;

		Pen::PenStyle frameLineStyle;
		FrameStyle frameStyle;
		unsigned int frameWidth;
		int frameXRadius, frameYRadius;
		Color frameColor;

		Pen framePen;
		Brush backgroundBrush;

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
		void setFrame(Pen::PenStyle lineStyle, FrameStyle style, unsigned int width, const Gdiplus::Color& color, int xRadius = 3, int yRadius = 3);
		void setBackgroundColor(const Color& color);
	//	void drawRoundedRectangle(Gdiplus::Graphics* graphics, const Rect& rect, unsigned char width);

		void initPanel();
		void flush(const Rect& rect);
	};

}

#endif
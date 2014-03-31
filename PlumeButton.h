#pragma once
#ifndef _PLUME_PLUMEBUTTON_H_
#define _PLUME_PLUMEBUTTON_H_
#include "PlumeComponent.h"

namespace Plume
{

	class PlumeButton :
		public PlumeComponent
	{
	private:
		int clicked;
		ConstStr text;
		struct ButtonColorStyle
		{
			ButtonColorStyle(Color top, Color middle1, Color middle2, Color buttom, Color frame1, Color frame2)
				: brushOne(Brush::GRADUAL, top, middle1, Brush::VERTICAL),
				brushTwo(Brush::GRADUAL, middle2, buttom, Brush::VERTICAL),
				framePenOne(frame1), framePenTwo(frame2)
			{
			}
			Brush brushOne, brushTwo;
			Pen framePenOne, framePenTwo;
		};
		ButtonColorStyle* currentStyle;
		ButtonColorStyle moveOnStyle, unclickedStyle, clickedStyle;
	public:
		PlumeButton(void);
		~PlumeButton(void);

		void draw(PlumeGraphics* graphics);

		bool leftButtonDown(int px, int py, KeyCondition condition);
		bool leftButtonUp(int px, int py, KeyCondition condition);

		bool rightButtonDown(int px, int py, KeyCondition condition);
		bool rightButtonUp(int px, int py, KeyCondition condition);

		bool middleButtonDown(int px, int py, KeyCondition condition);
		bool middleButtonUp(int px, int py, KeyCondition condition);

		bool mouseMove(int px, int py, KeyCondition condition);
		void setText(ConstStr pstr);
	};

}

#endif
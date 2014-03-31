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
			ButtonColorStyle(PlumeColor top, PlumeColor middle1, PlumeColor middle2, PlumeColor buttom, PlumeColor frame1, PlumeColor frame2)
				:colorTop(top), colorMiddle1(middle1), colorMiddle2(middle2), colorBottom(buttom), colorFrame1(frame1), colorFrame2(frame2)
			{
			}
			PlumeColor colorTop, colorMiddle1, colorMiddle2, colorBottom, colorFrame1, colorFrame2;
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
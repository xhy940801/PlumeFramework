#pragma once
#ifndef _PLUME_PLUMETYPEDEFINE_H_
#define _PLUME_PLUMETYPEDEFINE_H_

#include <Windows.h>
#include <GdiPlus.h>

namespace Plume
{
	typedef WPARAM KeyCondition;
	typedef WPARAM VirtualKeyCode;
	typedef LPARAM KeyInfo;
	typedef RECT Rect;
	typedef LPCTSTR ConstStr;

	enum MouseCondition
	{
		LeftButtonDown = MK_LBUTTON,
		RightButtonDown = MK_RBUTTON,
		MiddleButtonDown = MK_MBUTTON,
		Shift = MK_SHIFT,
		Control = MK_CONTROL
	};
}

#endif
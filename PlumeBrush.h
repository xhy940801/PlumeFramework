#pragma once
#ifndef _PLUME_PLUMEBRUSH_H_
#define _PLUME_PLUMEBRUSH_H_

#include <Windows.h>
#include <GdiPlus.h>

namespace Plume
{

	class PlumeBrush
	{
	public:
		PlumeBrush(void);
		~PlumeBrush(void);

		virtual Gdiplus::Brush* getBrush() const = 0;
	};

}

#endif
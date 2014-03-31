#pragma once
#ifndef _PLUME_PLUMEIMAGE_H_
#define _PLUME_PLUMEIMAGE_H_

#include <Windows.h>
#include <GdiPlus.h>

#include "PlumeTypeDefine.h"

namespace Plume
{

	class PlumeImage
	{
		Gdiplus::Image* pImage;
	public:
		PlumeImage(ConstStr);
		~PlumeImage(void);

	public:
		Gdiplus::Image* getPImage(void) const
		{
			return pImage;
		}
	};

}

#endif
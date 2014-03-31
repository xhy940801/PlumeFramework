#pragma once
#ifndef _PLUME_PLUMESOLIDPEN_H
#define _PLUME_PLUMESOLIDPEN_H

#include <Windows.h>
#include <GdiPlus.h>

#include "MemoryPool.h"
#include "PlumeGraphicsBaseGDITypeDefine.h"

namespace Plume
{

	/*class PlumeSolidPen :
		public PlumePen
	{
	private:
		static MemoryPool<PlumeSolidPen> solidPenPool;
		Gdiplus::Pen pen;
	public:
		PlumeSolidPen(void);
		~PlumeSolidPen(void);

	public:
		void* operator new(size_t sz);
		void operator delete(void* p);

		void setColor(const Color& color);
		Gdiplus::Pen* getPen();
	};*/

}

#endif
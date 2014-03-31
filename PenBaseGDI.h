#pragma once
#ifndef _PLUME_PENBASEGDI_H_
#define _PLUME_PENBASEGDI_H_
#include <Windows.h>
#include "PlumeGraphicsBaseGDITypeDefine.h"

namespace Plume
{

	class PenBaseGDI
	{
	public:
		enum PenStyle
		{
			SOLID, DASH, DOT, DASHDOT, DASHDOTDOT, BLANK
		};
		enum PenCapStyle
		{
			ROUNDCAP, FLATCAP
		};
		enum PenAlign
		{
			DEFAULT, INSIDEFRAME
		};
	public:
		PenBaseGDI(void);
		PenBaseGDI(const PenStyle penStyle);
		PenBaseGDI(const Color penColor);
		PenBaseGDI(const PenStyle penStyle, const Color penColor);
		PenBaseGDI(const PenStyle penStyle, const Color penColor, const int penWidth, const PenCapStyle penCapStyle, const PenAlign penAlign);
		PenBaseGDI(const PenBaseGDI& pen);
		~PenBaseGDI(void);

		PenBaseGDI& operator = (const PenBaseGDI& pen);

		void setColor(const Color penColor);
		void setStyle(const PenStyle penStyle);
		void setWidth(const int penWidth);
		void setAlign(const PenAlign penAlign);

		void setStatus(const Color penColor, const PenStyle penStyle, const int penWidth, const PenAlign penAlign);

	private:
		PenStyle style;
		PenCapStyle capStyle;
		PenAlign align;
		HPEN pen;
		Color color;
		int width;
		bool isStandard;
		friend class PlumeGraphicsBaseGDI;

	private:
		void initPen();
		void releasePen();
	};

}
#endif
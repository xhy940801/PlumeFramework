#pragma once
#ifndef _PLUME_BRUSHBASEGDI_H_
#define _PLUME_BRUSHBASEGDI_H_
#include <Windows.h>
#include "PlumeGraphicsBaseGDITypeDefine.h"

namespace Plume
{

	class BrushBaseGDI
	{
	public:
		enum BrushStyle
		{
			SOLID, HATCH, GRADUAL, BLANK
		};

		enum OtherInfo
		{
			BDIAGONAL = HS_BDIAGONAL,
			CROSS = HS_CROSS,
			FDIAGONAL = HS_FDIAGONAL,
			HORIZONTAL = HS_HORIZONTAL,	//ºáÏò
			VERTICAL = HS_VERTICAL,		//×ÝÏò
			DIAGCROSS = HS_DIAGCROSS,
			NONE = 1024
		};
	public:
		BrushBaseGDI(void);
		BrushBaseGDI(const BrushBaseGDI& brush);
		BrushBaseGDI(BrushStyle brushStyle, Color brushColor1, Color brushColor2, OtherInfo brushInfo = NONE);
		BrushBaseGDI(BrushStyle brushStyle, Color brushColor1, OtherInfo brushInfo = NONE, Color brushColor2 = Color::Black);
		~BrushBaseGDI(void);

		BrushBaseGDI& operator = (const BrushBaseGDI& brush);

		void setColor(const Color& colorO, const Color& colorT = Color::Black);

	private:
		void initBrush();
		void releaseBrush();

	private:
		BrushStyle style;
		OtherInfo info;
		HBRUSH brush;
		Color color1, color2;
		bool isStandard;
		friend class PlumeGraphicsBaseGDI;

	};

}

#endif
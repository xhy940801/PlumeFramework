#pragma once
#ifndef _PLUME_PLUMEGRAPHICSBASEGDIPLUS_H_
#define _PLUME_PLUMEGRAPHICSBASEGDIPLUS_H_

#include <Windows.h>
#include <GdiPlus.h>

#pragma comment(lib, "gdiplus.lib")

#include "PlumeImage.h"

namespace Plume
{
	typedef Gdiplus::Color PlumeColor;

	class PlumeGraphicsBaseGDIPlus
	{
	private:
		Gdiplus::Graphics* graphics;
		Gdiplus::Pen pen;
		Gdiplus::SolidBrush brush;

	public:
		typedef Gdiplus::DashStyle LineStyle;
		typedef Gdiplus::StringAlignment StringAlignment;
		enum LinearGradientStyle
		{
			Horizontal = 0,
			Vertical = 1
		};
	public:
		PlumeGraphicsBaseGDIPlus(Gdiplus::Graphics* graphics);
		~PlumeGraphicsBaseGDIPlus(void);
		bool drawLine(const PlumeColor& color, unsigned int width, int x1, int y1, int x2, int y2);
		bool drawEllipse(PlumeColor color, unsigned int lineWidth, int x1, int y1, int nWidth, int nHeight);
		bool drawRoundedRectangle(PlumeColor color, unsigned int width, int x1, int y1, int x2, int y2, unsigned int radius);
		bool drawRectangle(PlumeColor color, unsigned int lineWidth, int x1, int y1, int nWidth, int nHeight);
		bool drawImage(const PlumeImage& image, int x1, int y1, int width, int height);
		bool fillRectangle(PlumeColor color, int x1, int y1, int width, int height);
		void setLineStyle(LineStyle style);
		bool fillRectangleWithLinearGradient(PlumeColor color1, PlumeColor color2, int x1, int y1, int width, int height, LinearGradientStyle style);
		void getInnerRect(Rect& rect, unsigned int width);
		bool drawPoint(PlumeColor color, int x, int y);
		bool drawUnCornerRectangle(PlumeColor color, int lineWidth, int x1, int y1, int x2, int y2, int radius);
		bool drawCorner(PlumeColor color, int x1, int y1, int x2, int y2);
		bool drawText(ConstStr pstr, PlumeColor color, int x1, int y1, int width, int height, StringAlignment style);
	};

}

#endif
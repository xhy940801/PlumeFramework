#pragma once
#ifndef _PLUME_GRAPHICSBASEGDI_H_
#define _PLUME_GRAPHICSBASEGDI_H_

#include <Windows.h>
#include "MemoryPool.h"
#include "PlumeGraphicsBaseGDITypeDefine.h"
#include "PenBaseGDI.h"
#include "BrushBaseGDI.h"

namespace Plume
{
	struct Point
	{
		int x, y;
	};
	
	class PlumeGraphicsBaseGDI
	{
	private:
		HDC hdc;
		Point offset;
		PenBaseGDI pen;
		BrushBaseGDI brush;
	public:
		PlumeGraphicsBaseGDI(HDC dc);
		~PlumeGraphicsBaseGDI(void);
		void getOffset(Point& point);
		void setOffset(const Point& point);
		void setOffset(const int px, const int py);
		void setOffsetEx(const Point& newOffset, Point& oldOffset);
		void setOffsetEx(const int px, const int py, Point& oldOffset);

		void setPen(const PenBaseGDI& nPen);
		void setBrush(const BrushBaseGDI& nBrush);

		void getInnerPos(int& px, int& py, int& width, int& height);
		void getInnerPosV(int& px, int& py, int& width, int& height);

		void drawPixel(int x, int y, const Color& color);												//Draw a pixel
		void drawLine(int x1, int y1, int x2, int y2);													//Draw a line from p1(x1, y1) to p2(x2, y2) not include p2;
		void drawRectangleFr(int x, int y, int width, int height);										//Draw a rectangle just has frame
		void drawRoundRectangleFr(int x, int y, int width, int height, int xRadius, int yRadius);		//Use pen to draw the rounded rectangle frame
		void drawRectangleFi(int x, int y, int width, int height);
		void drawInnerRectRectangleFr(int x, int y, int width, int height, int xRadius, int yRadius);
		void drawEllipseFr(int x, int y, int xDiameter, int yDiameter);

	};

}
#endif
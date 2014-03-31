#include "PlumeGraphicsBaseGDI.h"

using namespace Plume;


PlumeGraphicsBaseGDI::PlumeGraphicsBaseGDI(HDC dc)
	: hdc(dc)
{
	offset.x = 0;
	offset.y = 0;
}


PlumeGraphicsBaseGDI::~PlumeGraphicsBaseGDI(void)
{
}


void PlumeGraphicsBaseGDI::getOffset(Point& point)
{
	point = offset;
}


void PlumeGraphicsBaseGDI::setOffset(const Point& point)
{
	offset = point;
}


void PlumeGraphicsBaseGDI::setOffset(const int px, const int py)
{
	offset.x = px;
	offset.y = py;
}


void PlumeGraphicsBaseGDI::setOffsetEx(const Point& newOffset, Point& oldOffset)
{
	oldOffset = offset;
	offset = newOffset;
}


void PlumeGraphicsBaseGDI::setOffsetEx(const int px, const int py, Point& oldOffset)
{
	oldOffset = offset;
	offset.x = px;
	offset.y = py;
}


void PlumeGraphicsBaseGDI::setPen(const PenBaseGDI& nPen)
{
	pen = nPen;
	SelectObject(hdc, pen.pen);
}

void PlumeGraphicsBaseGDI::setBrush(const BrushBaseGDI& nBrush)
{
	brush = nBrush;
	SelectObject(hdc, brush.brush);
}


void PlumeGraphicsBaseGDI::getInnerPos(int& px, int& py, int& width, int& height)
{
	px += pen.width/2;
	py += pen.width/2;
	width -= pen.width - 1;
	height -= pen.width - 1;
}


void PlumeGraphicsBaseGDI::getInnerPosV(int& px, int& py, int& width, int& height)
{
	px += pen.width/2;
	py += pen.width/2;
	width -= pen.width;
	height -= pen.width;
}


void PlumeGraphicsBaseGDI::drawPixel(int x, int y, const Color& color)
{
	SetPixel(hdc, offset.x + x, offset.y + y, color.ToCOLORREF());
}


void PlumeGraphicsBaseGDI::drawLine(int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, offset.x + x1, offset.y + y1, NULL);
	LineTo(hdc, offset.x + x2, offset.y + y2);
}


void PlumeGraphicsBaseGDI::drawRectangleFr(int x, int y, int width, int height)
{
	if(pen.isStandard == false)
	{
		switch(pen.align)
		{
		case PenBaseGDI::INSIDEFRAME:
			getInnerPos(x, y, width, height);
			break;
		default:
			break;
		}
	}
	x += offset.x;
	y += offset.y;
	HGDIOBJ newBrush = GetStockObject(NULL_BRUSH);
	HGDIOBJ oldBrush = SelectObject(hdc, newBrush);
	Rectangle(hdc, x, y, x + width, y + height);
	SelectObject(hdc, oldBrush);
}


void PlumeGraphicsBaseGDI::drawRoundRectangleFr(int x, int y, int width, int height, int xRadius, int yRadius)
{
	if(pen.isStandard == false)
	{
		switch(pen.align)
		{
		case PenBaseGDI::INSIDEFRAME:
			getInnerPos(x, y, width, height);
			break;
		default:
			break;
		}
	}
	x += offset.x;
	y += offset.y;
	int xDiameter = 2 * xRadius;
	int yDiameter = 2 * yRadius;
	/*Arc(hdc, x, y, x + xDiameter, y+ yDiameter, x + xRadius, y, x, y + yRadius);
	MoveToEx(hdc, x, y + yRadius, NULL);
	LineTo(hdc, x, y + height - yRadius);
	Arc(hdc, x, y + height - yDiameter, x + xDiameter, y + height, x, y + height - yRadius, x + xRadius, y + height);
	MoveToEx(hdc, x + xRadius, y + height, NULL);
	LineTo(hdc, x + width - xRadius, y + height);
	Arc(hdc, x + width - xDiameter, y + height - yDiameter, x + width, y + height, x + width - xRadius, y + height, x + width, y + height - yRadius);
	MoveToEx(hdc, x + width, y + height - yRadius, NULL);
	LineTo(hdc, x + width, y + yRadius);
	Arc(hdc, x + width - xDiameter, y, x + width, y + yDiameter, x + width, y + yRadius, x + width - xRadius, y);
	MoveToEx(hdc, x + width - xRadius, y, NULL);
	LineTo(hdc, x + xRadius, y);*/
	HGDIOBJ newBrush = GetStockObject(NULL_BRUSH);
	HGDIOBJ oldBrush = SelectObject(hdc, newBrush);
	RoundRect(hdc, x, y, x + width, y + height, xDiameter, xDiameter);
	SelectObject(hdc, oldBrush);
}


void PlumeGraphicsBaseGDI::drawRectangleFi(int x, int y, int width, int height)
{
	x += offset.x;
	y += offset.y;
	if(brush.isStandard)
	{
		HGDIOBJ newPen = GetStockObject(NULL_PEN);
		HGDIOBJ oldPen = SelectObject(hdc, newPen);
		Rectangle(hdc, x, y, x + width + 1, y + height + 1);
		SelectObject(hdc, oldPen);
	}
	else
	{
		switch(brush.style)
		{
		case BrushBaseGDI::GRADUAL:
			{
				int *pScan;
				int *pAdd;
				int graLength, totWidth;
				switch(brush.info)
				{
				case BrushBaseGDI::HORIZONTAL:
					graLength = width;
					totWidth = height;
					pScan = &y;
					pAdd = &x;
					break;
				case BrushBaseGDI::VERTICAL:
					graLength = height;
					totWidth = width;
					pScan = &x;
					pAdd = &y;
					break;
				default:
					return;
				}
				int r1 = brush.color1.GetR(), r2 = brush.color2.GetR();
				int g1 = brush.color1.GetG(), g2 = brush.color2.GetG();
				int b1 = brush.color1.GetB(), b2 = brush.color2.GetB();
				HPEN newPen = CreatePen(PS_SOLID, 1, brush.color1.ToCOLORREF());
				HGDIOBJ oldPen = SelectObject(hdc, newPen);
				for(int i=0;i<graLength;++i)
				{
					MoveToEx(hdc, x, y, NULL);
					(*pScan) += totWidth;
					LineTo(hdc, x, y);
					(*pScan) -= totWidth;
					MoveToEx(hdc, x, y, NULL);
					(*pAdd)++;
					DeleteObject(newPen);
					BYTE r = r1 + (r2 - r1) * i / graLength;
					BYTE g = g1 + (g2 - g1) * i / graLength;
					BYTE b = b1 + (b2 - b1) * i / graLength;
					newPen = CreatePen(PS_SOLID, 1, RGB(r, g, b));
					SelectObject(hdc, newPen);
					int err = GetLastError();
				}
				DeleteObject(newPen);
				SelectObject(hdc, oldPen);
				break;
			}
		}
	}
}


void PlumeGraphicsBaseGDI::drawInnerRectRectangleFr(int x, int y, int width, int height, int xRadius, int yRadius)
{
	int add = pen.width/2;
	if(pen.isStandard == false)
	{
		switch(pen.align)
		{
		case PenBaseGDI::INSIDEFRAME:
			getInnerPos(x, y, width, height);
			break;
		default:
			break;
		}
	}
	x += offset.x;
	y += offset.y;

	POINT points[12];

	points[0].x = x + xRadius;
	points[0].y = y;

	points[1].x = x + width - xRadius;
	points[1].y = y;

	points[2].x = x + width - xRadius;
	points[2].y = y + yRadius;

	points[3].x = x + width;
	points[3].y = y + yRadius;

	points[4].x = x + width;
	points[4].y = y + height - yRadius;

	points[5].x = x + width - xRadius;
	points[5].y = y + height - yRadius;

	points[6].x = x + width - xRadius;
	points[6].y = y + height;

	points[7].x = x + xRadius;
	points[7].y = y + height;

	points[8].x = x + xRadius;
	points[8].y = y + height - yRadius;

	points[9].x = x;
	points[9].y = y + height - yRadius;

	points[10].x = x;
	points[10].y = y + yRadius;

	points[11].x = x + xRadius;
	points[11].y = y + yRadius;

	HGDIOBJ newBrush = GetStockObject(NULL_BRUSH);
	HGDIOBJ oldBrush = SelectObject(hdc, newBrush);
	Polygon(hdc, points, 12);
	SelectObject(hdc, oldBrush);
}


void PlumeGraphicsBaseGDI::drawEllipseFr(int x, int y, int xDiameter, int yDiameter)
{
	if(pen.isStandard == false)
	{
		switch(pen.align)
		{
		case PenBaseGDI::INSIDEFRAME:
			getInnerPos(x, y, xDiameter, yDiameter);
			break;
		default:
			break;
		}
	}
	x += offset.x;
	y += offset.y;
	HGDIOBJ newBrush = GetStockObject(NULL_BRUSH);
	HGDIOBJ oldBrush = SelectObject(hdc, newBrush);
	Ellipse(hdc, x, y, x + xDiameter, y + yDiameter);
	SelectObject(hdc, oldBrush);
}
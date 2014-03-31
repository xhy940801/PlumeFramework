#include "PlumeGraphicsBaseGDIPlus.h"

using namespace Plume;


PlumeGraphicsBaseGDIPlus::PlumeGraphicsBaseGDIPlus(Gdiplus::Graphics* graphics)
	: pen(PlumeColor(0, 0, 0)), brush(Gdiplus::Color::White)
{
	this->graphics = graphics;
}


PlumeGraphicsBaseGDIPlus::~PlumeGraphicsBaseGDIPlus(void)
{
}


bool PlumeGraphicsBaseGDIPlus::drawLine(const PlumeColor& color, unsigned int width, int x1, int y1, int x2, int y2)
{
	pen.SetColor(color);
	pen.SetWidth(width);
	return graphics->DrawLine(&pen, x1, y1, x2, y2) == Gdiplus::Ok;
}


bool PlumeGraphicsBaseGDIPlus::drawEllipse(PlumeColor color, unsigned int lineWidth, int x1, int y1, int nWidth, int nHeight)
{
	pen.SetColor(color);
	pen.SetWidth(lineWidth);
	return graphics->DrawEllipse(&pen, x1, y1, nWidth, nHeight) == Gdiplus::Ok;
}


bool PlumeGraphicsBaseGDIPlus::drawRoundedRectangle(PlumeColor color, unsigned int width, int x1, int y1, int x2, int y2, unsigned int radius)
{
	pen.SetColor(color);
	pen.SetWidth(width);
	int diameter = radius * 2;
	int status = graphics->DrawLine(&pen, x1 + radius - 1, y1, x2 - radius + 1, y1);
	status |= graphics->DrawArc(&pen, x2 - diameter, y1, diameter, diameter, 270, 90);

	status |= graphics->DrawLine(&pen, x2, y1 + radius - 1, x2, y2 - radius + 1);
	status |= graphics->DrawArc(&pen, x2 - diameter, y2 - diameter, diameter, diameter, 0, 90);

	status |= graphics->DrawLine(&pen, x2 - radius + 1, y2, x1 + radius - 1, y2);
	status |= graphics->DrawArc(&pen, x1, y2 - diameter, diameter, diameter, 90, 90);

	status |= graphics->DrawLine(&pen, x1, y2 - radius + 1, x1, y1 + radius - 1);
	status |= graphics->DrawArc(&pen, x1, y1, diameter, diameter, 180, 90);
	return status == Gdiplus::Ok;
}


bool PlumeGraphicsBaseGDIPlus::drawRectangle(PlumeColor color, unsigned int lineWidth, int x1, int y1, int nWidth, int nHeight)
{
	pen.SetColor(color);
	pen.SetWidth(lineWidth);
	return graphics->DrawRectangle(&pen, x1, y1, nWidth, nHeight) == Gdiplus::Ok;
}


bool PlumeGraphicsBaseGDIPlus::drawImage(const PlumeImage& image, int x1, int y1, int width, int height)
{
	return graphics->DrawImage(image.getPImage(), x1, y1, width, height) == Gdiplus::Ok;
}


bool PlumeGraphicsBaseGDIPlus::fillRectangle(PlumeColor color, int x1, int y1, int width, int height)
{
	brush.SetColor(color);
	return graphics->FillRectangle(&brush, x1, y1, width, height);
}


void PlumeGraphicsBaseGDIPlus::setLineStyle(LineStyle style)
{
	pen.SetDashStyle(style);
}


bool PlumeGraphicsBaseGDIPlus::fillRectangleWithLinearGradient(PlumeColor color1, PlumeColor color2, int x1, int y1, int width, int height, LinearGradientStyle style)
{
	Gdiplus::Rect rect(x1, y1, width, height);
	switch(style)
	{
	case Horizontal:
		{
			Gdiplus::LinearGradientBrush linearGradientBrush(rect, color1, color2, Gdiplus::LinearGradientModeHorizontal);
			return graphics->FillRectangle(&linearGradientBrush, rect) == Gdiplus::Ok;
		}
	case Vertical:
		{
			Gdiplus::LinearGradientBrush linearGradientBrush(rect, color1, color2, Gdiplus::LinearGradientModeVertical);
			return graphics->FillRectangle(&linearGradientBrush, rect) == Gdiplus::Ok;
		}
	}
}


void PlumeGraphicsBaseGDIPlus::getInnerRect(Rect& rect, unsigned int width)
{
	rect.left += width/2;
	rect.top += width/2;
	rect.right -= (width + 1)/2;
	rect.bottom -= (width + 1)/2;
}


bool Plume::PlumeGraphicsBaseGDIPlus::drawPoint(PlumeColor color, int x, int y)
{
	pen.SetColor(color);
	pen.SetWidth(1);
	return graphics->DrawRectangle(&pen, x, y, 1, 1) == Gdiplus::Ok;
}


bool Plume::PlumeGraphicsBaseGDIPlus::drawUnCornerRectangle(PlumeColor color, int lineWidth, int x1, int y1, int x2, int y2, int radius)
{
	pen.SetColor(color);
	pen.SetWidth(lineWidth);
	int status = graphics->DrawLine(&pen, x1 + radius, y1, x2 - radius, y1);
	status |= graphics->DrawLine(&pen, x2, y1 + radius, x2, y2 - radius);
	status |= graphics->DrawLine(&pen, x2 - radius, y2, x1 + radius, y2);
	status |= graphics->DrawLine(&pen, x1, y2 - radius, x1, y1 + radius);
	return status == Gdiplus::Ok;
}


bool Plume::PlumeGraphicsBaseGDIPlus::drawCorner(PlumeColor color, int x1, int y1, int x2, int y2)
{
	pen.SetColor(color);
	pen.SetWidth(1);
	int status = graphics->FillRectangle(pen.GetBrush(), x1, y1, 1, 1);
	status |= graphics->FillRectangle(pen.GetBrush(), x2, y1, 1, 1);
	status |= graphics->FillRectangle(pen.GetBrush(), x2, y2, 1, 1);
	status |= graphics->FillRectangle(pen.GetBrush(), x1, y2, 1, 1);
	return status == Gdiplus::Ok;
}


bool Plume::PlumeGraphicsBaseGDIPlus::drawText(ConstStr pstr, PlumeColor color, int x1, int y1, int width, int height, StringAlignment style)
{
	brush.SetColor(color);
	Gdiplus::FontFamily fontFamily(L"¿¬Ìå");
	Gdiplus::Font font(&fontFamily, height/1.5, Gdiplus::FontStyleRegular, Gdiplus::UnitPoint);
	Gdiplus::StringFormat stringFormat;
	stringFormat.SetAlignment(style);
	graphics->DrawString(pstr, (INT)wcslen(pstr), &font, Gdiplus::RectF(x1, y1, width, height), &stringFormat, &brush);
	return false;
}

#include "BrushBaseGDI.h"

using namespace Plume;


BrushBaseGDI::BrushBaseGDI(void)
	: style(SOLID), color1(Color::Black), color2(Color::Black), info(NONE), brush(NULL)
{
	initBrush();
}


BrushBaseGDI::BrushBaseGDI(const BrushBaseGDI& brush)
	: style(brush.style), color1(brush.color1), color2(brush.color2), info(brush.info), brush(NULL)
{
	initBrush();
}


BrushBaseGDI::BrushBaseGDI(BrushStyle brushStyle, Color brushColor1, Color brushColor2, OtherInfo brushInfo)
	: style(brushStyle), color1(brushColor1), color2(brushColor2), info(brushInfo), brush(NULL)
{
	initBrush();
}


BrushBaseGDI::BrushBaseGDI(BrushStyle brushStyle, Color brushColor1, OtherInfo brushInfo, Color brushColor2)
	: style(brushStyle), color1(brushColor1), color2(brushColor2), info(brushInfo), brush(NULL)
{
	initBrush();
}


BrushBaseGDI::~BrushBaseGDI(void)
{
	releaseBrush();
}


void BrushBaseGDI::setColor(const Color& colorO, const Color& colorT)
{
	this->color1 = colorO;
	this->color2 = colorT;
}


BrushBaseGDI& BrushBaseGDI::operator = (const BrushBaseGDI& brush)
{
	releaseBrush();

	style = brush.style;
	color1 = brush.color1;
	color2 = brush.color2;
	info = brush.info;
	this->brush = NULL;

	initBrush();
	return *this;
}


void BrushBaseGDI::initBrush()
{
	switch(style)
	{
	case SOLID:
		brush = CreateSolidBrush(color1.ToCOLORREF());
		isStandard = true;
		break;
	case HATCH:
		brush = CreateHatchBrush(info, color1.ToCOLORREF());
		isStandard = true;
		break;
	case GRADUAL:
		brush = 0;
		if(info != HORIZONTAL && info != VERTICAL)
			info = VERTICAL;
		isStandard = false;
		break;
	}
}


void BrushBaseGDI::releaseBrush()
{
	if(brush)
		DeleteObject(brush);
}
#include "PenBaseGDI.h"

using namespace Plume;


PenBaseGDI::PenBaseGDI(void)
	: style(SOLID), color(Color::Black), width(1), capStyle(ROUNDCAP)
{
	initPen();
}


PenBaseGDI::PenBaseGDI(const PenStyle penStyle)
	: style(penStyle), color(Color::Black), width(1), capStyle(ROUNDCAP)
{
	initPen();
}


PenBaseGDI::PenBaseGDI(const Color penColor)
	: style(SOLID), color(penColor), width(1), capStyle(ROUNDCAP)
{
	initPen();
}


PenBaseGDI::PenBaseGDI(const PenStyle penStyle, const Color penColor)
	: style(penStyle), color(penColor), width(1), capStyle(ROUNDCAP)
{
	initPen();
}


PenBaseGDI::PenBaseGDI(const PenStyle penStyle, const Color penColor, const int penWidth, const PenCapStyle penCapStyle, const PenAlign penAlign)
	: style(penStyle), color(penColor), width(penWidth), capStyle(penCapStyle), align(penAlign)
{
	initPen();
}


PenBaseGDI::PenBaseGDI(const PenBaseGDI& pen)
	: style(pen.style), color(pen.color), width(pen.width), capStyle(pen.capStyle)
{
	initPen();
}


PenBaseGDI::~PenBaseGDI(void)
{
	releasePen();
}


PenBaseGDI& PenBaseGDI::operator = (const PenBaseGDI& pen)
{
	releasePen();
	style = pen.style;
	align = pen.align;
	color = pen.color;
	width = pen.width;
	capStyle = pen.capStyle;
	initPen();
	return *this;
}


void PenBaseGDI::initPen()
{
	LOGBRUSH logBrush;
	logBrush.lbStyle = BS_HATCHED;
	logBrush.lbColor = color.ToCOLORREF();
	logBrush.lbHatch = HS_CROSS;
	DWORD cap = PS_GEOMETRIC | PS_JOIN_MITER;
	switch(capStyle)
	{
	case ROUNDCAP:
		cap |= PS_ENDCAP_ROUND;
		break;
	case FLATCAP:
		cap |= PS_ENDCAP_FLAT;
		break;
	default:
		cap |= PS_ENDCAP_ROUND;
		break;
	}
	switch(style)
	{
	case SOLID:
		pen = ExtCreatePen(PS_SOLID | cap, width, &logBrush, 0, NULL);
		isStandard = true;
		break;
	case DASH:
		pen = ExtCreatePen(PS_DASH | cap, width, &logBrush, 0, NULL);
		isStandard = true;
		break;
	case DOT:
		pen = ExtCreatePen(PS_DOT | cap, width, &logBrush, 0, NULL);
		isStandard = true;
		break;
	case DASHDOT:
		pen = ExtCreatePen(PS_DASHDOT | cap, width, &logBrush, 0, NULL);
		isStandard = true;
		break;
	case DASHDOTDOT:
		pen = ExtCreatePen(PS_DASHDOTDOT | cap, width, &logBrush, 0, NULL);
		isStandard = true;
		break;
	case BLANK:
		pen = CreatePen(PS_NULL, width, color.ToCOLORREF());
		isStandard = true;
		break;
	default:
		break;
	}
	if(align == INSIDEFRAME)
		isStandard = false;
}


void PenBaseGDI::setColor(const Color penColor)
{
	color = penColor;
	releasePen();
	initPen();
}


void PenBaseGDI::setStyle(const PenStyle penStyle)
{
	style = penStyle;
	releasePen();
	initPen();
}


void PenBaseGDI::setWidth(const int penWidth)
{
	width = penWidth;
	releasePen();
	initPen();
}


void PenBaseGDI::setAlign(const PenAlign penAlign)
{
	align = penAlign;
	releasePen();
	initPen();
}


void PenBaseGDI::setStatus(const Color penColor, const PenStyle penStyle, const int penWidth, const PenAlign penAlign)
{
	color = penColor;
	style = penStyle;
	width = penWidth;
	align = penAlign;
	releasePen();
	initPen();
}


void PenBaseGDI::releasePen()
{
	if(pen)
		DeleteObject(pen);
}

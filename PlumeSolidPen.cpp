#include "PlumeSolidPen.h"

using namespace Plume;

MemoryPool<PlumeSolidPen> PlumeSolidPen::solidPenPool;


PlumeSolidPen::PlumeSolidPen(void)
	:pen(Gdiplus::Color::White)
{
}


PlumeSolidPen::~PlumeSolidPen(void)
{
}


void* PlumeSolidPen::operator new(size_t sz)
{
	return solidPenPool.bind();
}


void PlumeSolidPen::operator delete(void *p)
{
	solidPenPool.release((PlumeSolidPen*)p);
}


inline void PlumeSolidPen::setColor(const Color& color)
{
	pen.SetColor(color);
}


Gdiplus::Pen* PlumeSolidPen::getPen()
{
	return (&pen);
}
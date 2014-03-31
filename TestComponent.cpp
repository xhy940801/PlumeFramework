#include "TestComponent.h"

using namespace Plume;


TestComponent::TestComponent(void)
{
}


TestComponent::~TestComponent(void)
{
}


void TestComponent::draw(PlumeGraphics* graphics)
{
	Pen pen(Pen::SOLID, Color::White, 10, Pen::FLATCAP, Pen::INSIDEFRAME);
	Brush brush(Brush::GRADUAL, Color::Red, Color::Green);
	graphics->setBrush(brush);
	graphics->drawRectangleFi(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
	graphics->setPen(pen);
	graphics->drawRoundRectangleFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top, 20, 40);
//	graphics->drawRectangleFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top);
//	graphics->drawInnerRectRectangleFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top, 20, 40);
	
	
//	graphics->drawInnerRectRectangleFr(posRect.left, posRect.top, posRect.right - posRect.left, posRect.bottom - posRect.top, 20, 40);
}
#include "PlumeFrame.h"
#include "PlumePanel.h"
#include "PlumeEntryLayout.h"
#include "TestComponent.h"
#include "PlumeButton.h"
using namespace Plume;

int main()
{
	Plume::PlumeFrame* pframe = new Plume::PlumeFrame(L"xiao");
	pframe->setPosition(50, 50, 800, 600);
	pframe->setStyle(NULL, WS_CAPTION | WS_VISIBLE | WS_SYSMENU | WS_SIZEBOX);
	pframe->setLayout(new Plume::PlumeEntryLayout(200, 20, 30));
	Plume::PlumePanel* p1;
	p1 = new Plume::PlumePanel();
	p1->setFrame(Pen::SOLID, PlumePanel::RECTANGLE, 16, Color::White, 8, 8);
	p1->setBackgroundColor(Color::Yellow);
	p1->addComponent(new PlumeButton());
	p1->setLayout(new PlumeEntryLayout(200, 5, 5));
	pframe->addComponent(p1);
	pframe->show();
}
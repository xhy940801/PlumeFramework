#include "PlumeFrame.h"
#include "PlumeEntryLayout.h"
#include "PlumePanel.h"
#include "PlumeButton.h"

int main()
{
	Plume::PlumeFrame* pframe = new Plume::PlumeFrame(L"xiao");
	pframe->setPosition(50, 50, 800, 600);
	pframe->setStyle(NULL, WS_CAPTION | WS_VISIBLE | WS_SYSMENU | WS_SIZEBOX);
	pframe->setLayout(new Plume::PlumeEntryLayout(200, 20, 20));
	Plume::PlumePanel * sp1 = new Plume::PlumePanel(), *sp2 = new Plume::PlumePanel(), *sp3 = new Plume::PlumePanel();

	sp1->setBackgroundColor(new Gdiplus::Color(Gdiplus::Color::Blue));
	sp1->setFrame(Plume::PlumePanel::SOLID|Plume::PlumePanel::ROUNDEDRECTANGLE, 2, new Gdiplus::Color(Gdiplus::Color::Black), 2);

	sp2->setBackgroundColor(new Gdiplus::Color(Gdiplus::Color::Red));
	sp2->setFrame(Plume::PlumePanel::SOLID|Plume::PlumePanel::ELLIPSE, 1, new Gdiplus::Color(Gdiplus::Color::Black), 50);

	sp3->setBackgroundColor(new Gdiplus::Color(Gdiplus::Color::Green));
	sp3->setFrame(Plume::PlumePanel::SOLID|Plume::PlumePanel::RECTANGLE, 2, new Gdiplus::Color(Gdiplus::Color::Black), 0);
	sp1->setLayout(new Plume::PlumeEntryLayout(50, 30, 30));
	Plume::PlumeButton* pb = new Plume::PlumeButton();
	pb->setText(L"he;'[¹þ¹þ");
	sp1->addComponent(pb);
	pframe->addComponent(sp1);
	pframe->addComponent(sp2);
	pframe->addComponent(sp3);
	pframe->show();
}
#include "PlumeEntryLayout.h"

using namespace Plume;


PlumeEntryLayout::PlumeEntryLayout(int height, int roundGap, int cGap)
	: entryHeight(height), leftGap(roundGap), topGap(roundGap), rightGap(roundGap), componentGap(cGap)
{
}


PlumeEntryLayout::PlumeEntryLayout(int height, int lGap, int tGap, int rGap, int cGap)
	: entryHeight(height), leftGap(lGap), topGap(tGap), rightGap(rGap), componentGap(cGap)
{
}


PlumeEntryLayout::~PlumeEntryLayout(void)
{
}


void PlumeEntryLayout::addComponent(PlumeComponent* component)
{
	int topPos = topGap + components.size() * (entryHeight + componentGap);
	component->changePosRect(leftGap, topGap, containerWidth - rightGap, topGap + entryHeight);
	components.push_front(component);
}


void PlumeEntryLayout::deleteComponent(PlumeComponent* component)
{
	std::list<PlumeComponent*>::iterator it = components.begin();
	int i=0;
	for(;it != components.end();++it,++i)
	{
		if(*it == component)
		{
			components.erase(it);
			break;
		}
	}
	int addHeight = entryHeight + componentGap;
	int rightPos = containerWidth - rightGap;
	for(int n=topGap + i * addHeight;it != components.end();++it,n+=addHeight)
	{
		(*it)->changePosRect(leftGap, n, rightPos, n + entryHeight);
	}
}


void PlumeEntryLayout::flushContainerSize(const int width, const int height)
{
	if(this->isChange(width, height))
	{
		containerWidth = width;
		containerHeight = height;
		std::list<PlumeComponent*>::iterator it = components.begin();
		int addHeight = entryHeight + componentGap;
		int rightPos = width - rightGap;
		for(int i=topGap;it != components.end();++it,i+=addHeight)
			(*it)->changePosRect(leftGap, i, rightPos, i + entryHeight);
	}
}

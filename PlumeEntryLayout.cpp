#include "PlumeEntryLayout.h"

using namespace Plume;


PlumeEntryLayout::PlumeEntryLayout(int height, int rGap, int cGap)
	:entryHeight(height), roundedGap(rGap), componentGap(cGap)
{
}


PlumeEntryLayout::~PlumeEntryLayout(void)
{
}


void PlumeEntryLayout::addComponent(PlumeComponent* component)
{
	component->changePosRect(clientRect.left, clientRect.top + components.size() * (entryHeight + componentGap), clientRect.right, clientRect.top + components.size() * (entryHeight + componentGap) + entryHeight);
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
	for(;it != components.end();++it,++i)
	{
		(*it)->changePosRect(clientRect.left, clientRect.top + components.size() * (entryHeight + componentGap), clientRect.right, clientRect.top + components.size() * (entryHeight + componentGap) + entryHeight);
	}
}


void PlumeEntryLayout::flushClientRect(const Rect* rect)
{
	clientRect.left = rect->left + roundedGap;
	clientRect.top = rect->top + roundedGap;
	clientRect.right = rect->right - roundedGap;
	clientRect.bottom = rect->bottom - roundedGap;
	std::list<PlumeComponent*>::iterator it = components.begin();
	for(int i=clientRect.top + (components.size() - 1) * (entryHeight + componentGap);it != components.end();++it,i-=(entryHeight + componentGap))
		(*it)->changePosRect(clientRect.left, i, clientRect.right, i + entryHeight);
}

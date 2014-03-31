#pragma once
#ifndef _PLUME_PLUMEENTRYLAYOUT_H_
#define _PLUME_PLUMEENTRYLAYOUT_H_

#include "PlumeLayout.h"
#include "PlumeComponent.h"

#include <list>

namespace Plume
{

	class PlumeEntryLayout :
		public PlumeLayout
	{
	private:
		int entryHeight;
		int leftGap, topGap, rightGap;
		int componentGap;
		std::list<PlumeComponent*> components;
	public:
		PlumeEntryLayout(int height, int roundGap = 2, int cGap = 2);
		PlumeEntryLayout(int height, int lGap, int tGap, int rGap, int cGap);
		~PlumeEntryLayout(void);

		void addComponent(PlumeComponent* component);
		void deleteComponent(PlumeComponent* component);
		void flushContainerSize(const int width, const int height);
	};

}

#endif
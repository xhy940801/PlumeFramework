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
		int roundedGap;
		int componentGap;
		std::list<PlumeComponent*> components;
	public:
		PlumeEntryLayout(int height, int rGap = 2, int cGap = 2);
		~PlumeEntryLayout(void);

		void addComponent(PlumeComponent* component);
		void deleteComponent(PlumeComponent* component);
		void flushClientRect(const Rect* rect);
	};

}

#endif
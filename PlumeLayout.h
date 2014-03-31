#pragma once
#ifndef _PLUME_PLUMELAYOUT_H_
#define _PLUME_PLUMELAYOUT_H_

#include "PlumeComponent.h"
#include "PlumeTypeDefine.h"

namespace Plume
{
	class PlumeComponent;
	class PlumeLayout
	{
	protected:
		int containerWidth, containerHeight;	//¸¸´°¿Ú³ß´ç

	public:
		PlumeLayout(void);
		~PlumeLayout(void);

		virtual void addComponent(PlumeComponent* component);
		virtual void deleteComponent(PlumeComponent* component);
		virtual void flushContainerSize(const int width, const int height);

		static PlumeLayout defaultLayout;
	protected:
		bool isChange(const int width, const int height)
		{
			return containerWidth != width || containerHeight != height;
		}
	};

}

#endif
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
		Rect clientRect;	// 父窗口的大小

	public:
		PlumeLayout(void);
		~PlumeLayout(void);

		virtual void addComponent(PlumeComponent* component);
		virtual void deleteComponent(PlumeComponent* component);
		virtual void flushClientRect(const Rect* rect);

		static PlumeLayout defaultLayout;
	protected:
		bool isChange(const Rect& rect)
		{
			return rect.left == clientRect.left && rect.right == clientRect.right && rect.top == clientRect.top && rect.bottom == clientRect.bottom;
		}
	};

}

#endif
#pragma once
#ifndef _PLUME_PLUMECONTAINER_H_
#define _PLUME_PLUMECONTAINER_H_

#include "PlumeTypeDefine.h"

namespace Plume
{

	class PlumeContainer
	{
	public:
		PlumeContainer(void);
		~PlumeContainer(void);
		virtual void flush(const Rect& rect) = 0;
	};

}

#endif
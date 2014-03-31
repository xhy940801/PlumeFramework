#pragma once
#ifndef _PLUME_TESTCOMPONENT_H_
#define _PLUME_TESTCOMPONENT_H_
#include "plumecomponent.h"


namespace Plume
{

	class TestComponent :
		public PlumeComponent
	{
	public:
		TestComponent(void);
		~TestComponent(void);
		void draw(PlumeGraphics* graphics);
	};

}

#endif
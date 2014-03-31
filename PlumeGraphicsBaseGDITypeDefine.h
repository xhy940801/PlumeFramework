#pragma once
#ifndef _PLUME_PLUMEGRAPHICSBASEGDITYPEDEFINE_H_
#define _PLUME_PLUMEGRAPHICSBASEGDITYPEDEFINE_H_
#include <Windows.h>
#include <GdiPlus.h>
#include <string>

namespace Plume
{
	typedef Gdiplus::Color Color;
#ifdef _UNICODE
	typedef std::wstring PString;
#else
	typedef std::string PString;
#endif
}

#endif
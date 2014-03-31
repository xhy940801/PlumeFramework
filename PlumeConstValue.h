#include <Windows.h>
#pragma once

namespace Plume
{
	static const LPCWSTR WINDOW_CLASS_NAME = L"Xiao_Plume";

	LRESULT CALLBACK WindowProc(HWND hwnd,
								UINT msg,
								WPARAM wParam,
								LPARAM lParam);
}


namespace PlumeWindowsInfo
{
	static HINSTANCE ghInstance;
};
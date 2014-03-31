#pragma once
#ifndef _PLUME_PLUMEFRAME_H_
#define _PLUME_PLUMEFRAME_H_

#include <Windows.h>
#include <map>
#include <vector>

#include "PlumeConstValue.h"
#include "PlumeTypeDefine.h"

#include "PlumeComponent.h"
#include "PlumeLayout.h"

#include "PlumeGraphics.h"

namespace Plume
{
	class PlumeComponent;
	class PlumeLayout;
	class PlumeFrame
	{
	protected:
		static std::map<HWND, PlumeFrame*> hwndMap;

		HWND hwnd;

		DWORD dwExStyle;		// 窗口的扩展风格
		LPCTSTR lpWindowName;	// 指向窗口名称的指针
		DWORD dwStyle;			// 窗口风格

		Rect windowsRect, clientRect; //窗口的位置矩阵与客户区的位置矩阵(客户区矩阵暂时未使用)

		std::vector<PlumeComponent*> components;
		PlumeLayout *layout;
	public:
		static void insertHWND(HWND hWnd, PlumeFrame* p)
		{
			hwndMap.insert(std::pair<HWND, PlumeFrame*>(hWnd, p));
		}

		static void eraseHWND(HWND hWnd)
		{
			hwndMap.erase(hWnd);
		}

		static PlumeFrame* getFrame(HWND hWnd)
		{
			std::map<HWND, PlumeFrame*>::iterator it = PlumeFrame::hwndMap.find(hWnd);
			if(it == PlumeFrame::hwndMap.end())
				return 0;
			else
				return it->second;
		}

		PlumeFrame(void);
		~PlumeFrame(void);
		bool show(void);
		PlumeFrame(int width, int height);
		PlumeFrame(int px, int py, int width, int height);
		PlumeFrame(LPCWSTR name);
		PlumeFrame(int px, int py, LPCWSTR name, int width, int height, DWORD exStyle, DWORD style);
		void setStyle(DWORD exStyle, DWORD style);
		void setPosition(int px, int py, int width, int height);
		bool flushPos(void);
		void onCreate(void);
		void rePaint(void);
		void destroy(void);

		int hwndToInt(void)
		{
			return *((int*)&hwnd);
		}

		void setCapture()
		{
			SetCapture(hwnd);
		}

		void releaseCapture()
		{
			ReleaseCapture();
		}
		static int hwndToInt(HWND hWnd)
		{
			return *((int*)&hWnd);
		}

		void leftButtonDown(UINT msg, WPARAM wParam, LPARAM lParam);
		void leftButtonUp(UINT msg, WPARAM wParam, LPARAM lParam);
		void leftButtonDoubleClick(UINT msg, WPARAM wParam, LPARAM lParam);

		void rightButtonDown(UINT msg, WPARAM wParam, LPARAM lParam);
		void rightButtonUp(UINT msg, WPARAM wParam, LPARAM lParam);
		void rightButtonDoubleClick(UINT msg, WPARAM wParam, LPARAM lParam);

		void middleButtonDown(UINT msg, WPARAM wParam, LPARAM lParam);
		void middleButtonUp(UINT msg, WPARAM wParam, LPARAM lParam);
		void middleButtonDoubleClick(UINT msg, WPARAM wParam, LPARAM lParam);

		void keyDown(UINT msg, WPARAM wParam, LPARAM lParam);
		void keyUp(UINT msg, WPARAM wParam, LPARAM lParam);
		void systemKeyDown(UINT msg, WPARAM wParam, LPARAM lParam);
		void systemKeyUp(UINT msg, WPARAM wParam, LPARAM lParam);

		void mouseMove(UINT msg, WPARAM wParam, LPARAM lParam);

		void init(void);
		int addComponent(PlumeComponent* pComponent);
		void flush(void);
		PlumeComponent* deleteComponent(unsigned int n);
		
		void setLayout(PlumeLayout* PlumeLayout);
	};
}

#endif
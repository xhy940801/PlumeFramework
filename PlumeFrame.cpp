#include "PlumeFrame.h"

using namespace Plume;

std::map<HWND, PlumeFrame*> PlumeFrame::hwndMap;


PlumeFrame::PlumeFrame(void)
	:lpWindowName(L"Plume"), dwExStyle(NULL), dwStyle(WS_BORDER | WS_VISIBLE)
{
	windowsRect.left = 0;
	windowsRect.top = 0;
	windowsRect.right = 500;
	windowsRect.bottom = 500;
	init();
}


PlumeFrame::~PlumeFrame(void)
{
}


bool PlumeFrame::show(void)
{
	if(!(this->hwnd = CreateWindowEx(	this->dwExStyle,
		Plume::WINDOW_CLASS_NAME,
		this->lpWindowName,
		this->dwStyle,
		windowsRect.left, windowsRect.top,
		windowsRect.right - windowsRect.left, windowsRect.bottom - windowsRect.top,
		NULL,
		NULL,
		PlumeWindowsInfo::ghInstance,
		NULL)))
		return false;
	else
	{
		insertHWND(hwnd, this);
		return true;
	}
}


PlumeFrame::PlumeFrame(int width, int height)
	:lpWindowName(L"Plume"), dwExStyle(NULL), dwStyle(WS_BORDER | WS_VISIBLE)
{
	windowsRect.left = 0;
	windowsRect.top = 0;
	windowsRect.right = width;
	windowsRect.bottom = height;
	init();
}


PlumeFrame::PlumeFrame(int px, int py, int width, int height)
	:lpWindowName(L"Plume"), dwExStyle(NULL), dwStyle(WS_BORDER | WS_VISIBLE)
{
	windowsRect.left = px;
	windowsRect.top = py;
	windowsRect.right = width + px;
	windowsRect.bottom = height + py;
	init();
}


PlumeFrame::PlumeFrame(LPCWSTR name)
	:lpWindowName(name), dwExStyle(NULL), dwStyle(WS_BORDER | WS_VISIBLE)
{
	windowsRect.left = 0;
	windowsRect.top = 0;
	windowsRect.right = 500;
	windowsRect.bottom = 500;
	init();
}


PlumeFrame::PlumeFrame(int px, int py, LPCWSTR name, int width, int height, DWORD exStyle, DWORD style)
	:lpWindowName(name), dwExStyle(exStyle), dwStyle(style)
{
	windowsRect.left = px;
	windowsRect.top = py;
	windowsRect.right = width + px;
	windowsRect.bottom = height + py;
	init();
}


void PlumeFrame::setStyle(DWORD exStyle, DWORD style)
{
	this->dwExStyle = exStyle;
	this->dwStyle = style;
}


void PlumeFrame::setPosition(int px, int py, int width, int height)
{
	windowsRect.left = px;
	windowsRect.top = py;
	windowsRect.right = width + px;
	windowsRect.bottom = height + py;
}


bool PlumeFrame::flushPos(void)
{
	return SUCCEEDED(MoveWindow(hwnd, windowsRect.left, windowsRect.top,windowsRect.right - windowsRect.left, windowsRect.bottom - windowsRect.top, true));
}


void PlumeFrame::onCreate(void)
{
}


void PlumeFrame::rePaint(void)
{
	GetWindowRect(hwnd, &windowsRect);
	GetClientRect(hwnd, &clientRect);
	PAINTSTRUCT ps;

	HDC hdc;
	hdc = BeginPaint(hwnd, &ps);
	Gdiplus::Bitmap bmp(ps.rcPaint.right,ps.rcPaint.bottom);
	Gdiplus::Graphics graphics(&bmp);
	layout->flushClientRect(&clientRect);
	graphics.Clear(Gdiplus::Color::White);
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	PlumeGraphics plumeGraphics(&graphics);
	for(unsigned int i=0;i<components.size();++i)
		components[i]->draw(&plumeGraphics);
	Gdiplus::Graphics g(hdc);
	Gdiplus::CachedBitmap cachedBmp(&bmp,&g);
	g.DrawCachedBitmap(&cachedBmp, 0, 0);
//	g.DrawImage(&bmp, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);
	EndPaint(hwnd, &ps);
}


void PlumeFrame::destroy(void)
{
	eraseHWND(hwnd);
	PostQuitMessage(0);
}


void PlumeFrame::leftButtonDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->leftButtonDown(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::leftButtonUp(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->leftButtonUp(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::leftButtonDoubleClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->leftButtonDoubleClick(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::rightButtonDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->rightButtonDown(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::rightButtonUp(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->rightButtonUp(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::rightButtonDoubleClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->rightButtonDoubleClick(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::middleButtonDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->middleButtonDown(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::middleButtonUp(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->middleButtonUp(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::middleButtonDoubleClick(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->middleButtonDoubleClick(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::keyDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->keyDown(wParam, lParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::systemKeyDown(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->systemKeyDown(wParam, lParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::keyUp(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->keyUp(wParam, lParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::systemKeyUp(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->systemKeyUp(wParam, lParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}


void PlumeFrame::init(void)
{
	layout = &PlumeLayout::defaultLayout;
}


int PlumeFrame::addComponent(PlumeComponent* pComponent)
{
	components.push_back(pComponent);
	layout->addComponent(pComponent);
	pComponent->setFrame(this);
	return components.size() - 1;
}


void PlumeFrame::flush(void)
{
	GetWindowRect(hwnd, &windowsRect);
	GetClientRect(hwnd, &clientRect);

	HDC hdc;
	hdc = GetDC(hwnd);
	Gdiplus::Bitmap bmp(clientRect.right,clientRect.bottom);
	Gdiplus::Graphics graphics(&bmp);
	layout->flushClientRect(&clientRect);
	graphics.Clear(Gdiplus::Color::White);
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	graphics.SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAliasGridFit);
	PlumeGraphics plumeGraphics(&graphics);
	for(unsigned int i=0;i<components.size();++i)
		components[i]->draw(&plumeGraphics);
	Gdiplus::Graphics g(hdc);
	Gdiplus::CachedBitmap cachedBmp(&bmp,&g);
	g.DrawCachedBitmap(&cachedBmp, 0, 0);
//	g.DrawImage(&bmp, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);
	ReleaseDC(hwnd, hdc);
}


PlumeComponent* PlumeFrame::deleteComponent(unsigned int n)
{
#ifdef _DEBUG
	if(n < 0 || n >= components.size())
	{
		return 0;
	}
#endif
	PlumeComponent* p = components[n];
	components[n] = components[components.size() - 1];
	components.pop_back();
	layout->deleteComponent(p);
	return p;
}


void PlumeFrame::setLayout(PlumeLayout* PlumeLayout)
{
	layout = PlumeLayout;
	for(unsigned int i=0;i<components.size();++i)
		layout->addComponent(components[i]);
}


void PlumeFrame::mouseMove(UINT msg, WPARAM wParam, LPARAM lParam)
{
	for(unsigned int i=0;i<components.size();++i)
	{
		if(components[i]->mouseMove(LOWORD(lParam), HIWORD(lParam), wParam))
			return;
	}
	DefWindowProc(hwnd, msg, wParam, lParam);
}
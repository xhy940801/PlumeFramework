#include <Windows.h>

#include "PlumeConstValue.h"
#include "PlumeFrame.h"


int main();

int WINAPI WinMain(	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpcmdLine,
	int ncmdShow)
{
	WNDCLASSEX winClass;
	MSG msg;

	winClass.cbSize				= sizeof(WNDCLASSEX);
	winClass.style				= CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc		= Plume::WindowProc;
	winClass.cbClsExtra			= 0;
	winClass.cbWndExtra			= 0;
	winClass.hInstance			= hInstance;
	winClass.hIcon				= LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor			= LoadCursor(NULL, IDC_ARROW); 
	winClass.hbrBackground		= (HBRUSH)GetStockObject(BLACK_BRUSH);
	winClass.lpszMenuName		= NULL;
	winClass.lpszClassName		= Plume::WINDOW_CLASS_NAME;
	winClass.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);

	PlumeWindowsInfo::ghInstance = hInstance;

	if(!RegisterClassEx(&winClass))
		return 0;

	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartupInput gdiInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiInput, NULL);
	main();
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
	Gdiplus::GdiplusShutdown(gdiplusToken);
}


LRESULT CALLBACK Plume::WindowProc(HWND hwnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{
	PlumeFrame *pFrame = PlumeFrame::getFrame(hwnd);
	if(pFrame == 0)
		return DefWindowProc(hwnd, msg, wParam, lParam);
	switch(msg)
	{
	case WM_CREATE:
		pFrame->onCreate();
		return 0;
	case WM_PAINT:
		pFrame->rePaint();
		return 0;
	case WM_DESTROY:
		pFrame->destroy();
		return 0;
	case WM_ERASEBKGND:
		return 0;
		// Mouse event
	case WM_LBUTTONDOWN:
		pFrame->leftButtonDown(msg, wParam, lParam);
		return 0;
	case WM_RBUTTONDOWN:
		pFrame->rightButtonDown(msg, wParam, lParam);
		return 0;
	case WM_MBUTTONDOWN:
		pFrame->middleButtonDown(msg, wParam, lParam);
		return 0;
	case WM_LBUTTONUP:
		pFrame->leftButtonUp(msg, wParam, lParam);
		return 0;
	case WM_RBUTTONUP:
		pFrame->rightButtonUp(msg, wParam, lParam);
		return 0;
	case WM_MBUTTONUP:
		pFrame->middleButtonUp(msg, wParam, lParam);
		return 0;
	case WM_LBUTTONDBLCLK:
		pFrame->leftButtonDoubleClick(msg, wParam, lParam);
		return 0;
	case WM_RBUTTONDBLCLK:
		pFrame->rightButtonDoubleClick(msg, wParam, lParam);
		return 0;
	case WM_MBUTTONDBLCLK:
		pFrame->middleButtonDoubleClick(msg, wParam, lParam);
		return 0;
		//Keyboard event
	case WM_KEYDOWN:
		pFrame->keyDown(msg, wParam, lParam);
		return 0;
	case WM_SYSKEYDOWN:
		pFrame->systemKeyDown(msg, wParam, lParam);
		return 0;
	case WM_KEYUP:
		pFrame->keyUp(msg, wParam, lParam);
		return 0;
	case WM_SYSKEYUP:
		pFrame->systemKeyUp(msg, wParam, lParam);
		return 0;
	case WM_MOUSEMOVE:
		pFrame->mouseMove(msg, wParam, lParam);
	default:
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
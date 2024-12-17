#include "game.h"

namespace dewcin
{
	Game::Game()
	{
		windowTitle = L"PlatoGame";
		windowWidth = 1280;
		windowHeight = 720;
	}

	LRESULT CALLBACK WindowCallback(
		HWND windowHandle,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
	)
	{
		LRESULT result = 0;

		switch (message)
		{
		case WM_CLOSE:
		{
			Game::getInstance().running = false;
			OutputDebugString(L"window close\n");
		}	break;

		case WM_DESTROY:
		{
			Game::getInstance().running = false;
			OutputDebugString(L"window destroy\n");
		}	break;

		case WM_PAINT:
		{
			OutputDebugString(L"window paint\n");

			PAINTSTRUCT paint;
			HDC device_context = BeginPaint(windowHandle, &paint);

			FillRect(device_context, &paint.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));

			EndPaint(windowHandle, &paint);
		}	break;

		default:
			result = DefWindowProc(windowHandle, message, wParam, lParam);
		}

		return result;
	}

	void Game::startWindow()
	{
		const wchar_t* className = L"dewcin_window";

		WNDCLASS windowClass = {};

		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = WindowCallback;
		windowClass.hInstance = hInstance;
		windowClass.lpszClassName = className;

		if (!RegisterClass(&windowClass))
		{
			OutputDebugString(L"Failed to register window class\n");
			return;
		}

		windowHandle = CreateWindowEx(
			0,
			className,
			windowTitle.c_str(),
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			windowWidth,
			windowHeight,
			0,
			0,
			hInstance,
			0
		);

		if (windowHandle)
		{
			OutputDebugString(L"GAME INIT\n");
			running = true;

			while (running)
			{
				MSG message;
				while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
				{
					if (message.message == WM_QUIT)
						running = false;

					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}

			getInstance().update(0.0f);
		}
		else
		{
			OutputDebugString(L"Failed to create a window");
			return;
		}
	}
}
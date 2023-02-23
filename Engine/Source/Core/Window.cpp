#include "DrnPCH.h"
#include "Window.h"

namespace Drn
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_SIZE:
			//Display::Resize((UINT)(UINT64)lParam & 0xFFFF, (UINT)(UINT64)lParam >> 16);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

	void Window::Init()
	{
		std::cout << "Start window";

		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInstance;
		wcex.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = Title.c_str();
		wcex.hIconSm = LoadIcon(m_hInstance, IDI_APPLICATION);
		//ASSERT(0 != RegisterClassEx(&wcex), "Unable to register a window");
		bool result = RegisterClassEx(&wcex);


		RECT rc = { 0, 0, (LONG)Width, (LONG)Height };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

		m_WindowHandle = CreateWindow(Title.c_str(), Title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, m_hInstance, nullptr);



		ShowWindow(m_WindowHandle, SW_SHOWDEFAULT);
	}

	void Window::Shutdown()
	{
		std::cout << "Shutdown window";
	}

	void Window::Tick(float DeltaTime)
	{
		
	}

	void Window::Resize(int16 InWidth, int16 InHeight)
	{
		Width = InWidth;
		Height = InHeight;
	}
}
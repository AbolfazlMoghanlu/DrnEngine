#include "DrnPCH.h"
#include "Application.h"
#include "Window.h"

namespace Drn
{
	void Application::Run(HINSTANCE inhInstance)
	{
		m_Window = std::make_unique<Window>(inhInstance, std::wstring(L"Untitled window"));

		Startup();

		while (bRunning)
		{
			Tick(1.0f);
		}

		Shutdown();
	}

	void Application::Startup()
	{
		std::cout << "Start application";

		

	}

	void Application::Shutdown()
	{
		std::cout << "Shutdown application";
	}

	void Application::Tick(float DeltaTime)
	{
		m_Window->Tick(DeltaTime);
	}
}
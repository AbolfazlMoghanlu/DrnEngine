#include "DrnPCH.h"
#include "Application.h"

namespace Drn
{
	void Application::Run()
	{
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

	}
}
#pragma once

namespace Drn
{
	class Application
	{
	public:
		virtual void Run();

	protected:
		virtual void Startup();
		virtual void Shutdown();

		virtual void Tick(float DeltaTime);

		bool bRunning = true;
	};
}
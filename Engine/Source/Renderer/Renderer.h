#pragma once

namespace Drn
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void Tick(float DeltaTime);

		static ID3D12Device* g_Device;

	private:

	};
}



#pragma once

namespace Drn
{
	class Window
	{
	public:
		Window(std::string& InTitle, int16 InWidth = 800, int16 InHeight = 600)
		: Title(InTitle)
		, Width(InWidth)
		, Height(InHeight)
	{}

	public:
		void Resize(int16 InWidth, int16 InHeight);
	
	protected:
		uint16 Width;
		uint16 Height;

		std::string Title;

	private:
	};
}


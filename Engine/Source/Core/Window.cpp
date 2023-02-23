#include "DrnPCH.h"
#include "Window.h"

namespace Drn
{
	void Window::Resize(int16 InWidth, int16 InHeight)
	{
		Width = InWidth;
		Height = InHeight;
	}
}
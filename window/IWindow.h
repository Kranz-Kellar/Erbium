#pragma once

namespace Erbium {

	class IWindow
	{
	public:
		IWindow();
		virtual ~IWindow() = 0;

		virtual void initWindow() = 0;
		virtual void ShouldClose() = 0;
		virtual void SwapBuffers() = 0;
	};

}
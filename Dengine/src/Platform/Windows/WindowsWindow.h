#pragma once

#include "Engine/core.h"
#include "Engine/Window.h"

#include <GLFW/glfw3.h>

namespace Denji {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return _Data.Width; }
		inline unsigned int GetHeight() const override { return _Data.Height; }
		
		inline void SetEventCallback(const EventCallbackFn& callback) override { _Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* _Window;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData _Data;
	};
}
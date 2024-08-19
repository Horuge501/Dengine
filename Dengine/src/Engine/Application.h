#pragma once

#include "Core.h"

namespace Denji {
	class DENJI_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

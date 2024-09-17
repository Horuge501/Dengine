#pragma once

#ifdef DENJI_PLATFORM_WINDOWS
extern Denji::Application* Denji::CreateApplication();

int main(int arc, char** arcv) {
	Denji::Log::Init();
	auto app = Denji::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Only support Windows
#endif

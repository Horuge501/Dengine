#pragma once

#ifdef DENJI_PLATFORM_WINDOWS
extern Denji::Application* Denji::CreateApplication();

int main(int arc, char** arcv) {
	auto app = Denji::CreateApplication();
	Denji::Log* log = new Denji::Log("TestLog");
	log->Print("Entry point print", __FILE__, __LINE__);
	LOG("Entry point print");
	LOG_TEST("{0} {1} random numbers", 20, 32);
	PRINT_LOG("Log");
	PRINT_ERROR("Error");
	PRINT_INFO("Info");
	app->Run();
	delete app;
}
#else
	#error Only support Windows
#endif

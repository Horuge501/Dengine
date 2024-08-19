#pragma
#include <Dengine.h>


class Tactics : public Denji::Application {
public:
	Tactics() {

	}

	~Tactics() {

	}
};

Denji::Application* CreateApplication() {
	return new Tactics();
}
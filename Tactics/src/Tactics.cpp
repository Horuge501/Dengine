#pragma
#include <Dengine.h>


class Tactics : public Denji::Application {
public:
	Tactics() {

	}

	~Tactics() {

	}
};

Denji::Application* Denji::CreateApplication() {
	return new Tactics();
}
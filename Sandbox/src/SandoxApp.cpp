#include <Khaos.h>

class Sandbox : public Khaos::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Khaos::Application* Khaos::CreateApplication() {
	return new Sandbox();
}
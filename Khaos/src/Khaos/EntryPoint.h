#pragma once

#ifdef KH_PLATFORM_WINDOWS

extern Khaos::Application* Khaos::CreateApplication();

int main(int argc, char** argv) {
	auto app = Khaos::CreateApplication();
	app->Run();
	delete app;
}

#endif
#pragma once

#ifdef KH_PLATFORM_WINDOWS

extern Khaos::Application* Khaos::CreateApplication();

int main(int argc, char** argv) {

	Khaos::Log::Init();
	KH_CORE_WARN("Initialized Log!");
	int a = 5;
	KH_INFO("Hello! Var={0}", a);

	auto app = Khaos::CreateApplication();
	app->Run();
	delete app;
}

#endif
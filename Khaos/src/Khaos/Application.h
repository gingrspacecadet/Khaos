#pragma once

#include "Core.h"

namespace Khaos{
	
	class KHAOS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
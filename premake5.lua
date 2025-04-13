workspace "Khaos"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Khaos"
	location "Khaos"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"KH_PLATFORM_WINDOWS",
			"KH_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		"Khaos/vendor/spdlog/include",
		"Khaos/src"
	}
	
	links 
	{
		"Khaos"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }
		
		defines
		{
			"KH_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "KH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KH_DIST"
		optimize "On"

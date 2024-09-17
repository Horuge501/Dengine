workspace "Dengine"
	architecture "x64"
	startproject "Tactics"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Dengine/vendor/GLFW/include"

include "Dengine/vendor/GLFW"

project "Dengine"
	location "Dengine"
	kind "SharedLib"
	language "C++"


	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "denjipch.h"
	pchsource "Dengine/src/denjipch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		runtime "Release"
		systemversion "latest"

		defines{
			"DENJI_PLATFORM_WINDOWS",
			"DENJI_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Tactics")
		}

	filter "configurations:Debug"
		defines "DENJI_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "DENJI_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DENJI_DIST"
		buildoptions "/MD"
		optimize "On"

project "Tactics"
	location "Tactics"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Dengine/src"
	}

	links{
		"Dengine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		runtime "Release"
		systemversion "latest"

		defines{
			"DENJI_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "DENJI_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "DENJI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DENJI_DIST"
		optimize "On"
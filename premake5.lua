workspace "Dengine"
	architecture "x64"
	startproject "Tactics"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Dengine"
	location "Dengine"
	kind "SharedLib"
	language "C++"


	targetdir ("bin/" .. outputdir .. "%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
		optimize "On"

	filter "configurations:Release"
		defines "DENJI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DENJI_DIST"
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
		cppdialect "C++17"
		staticruntime "On"
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
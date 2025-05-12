workspace("KhoPhee")
configurations({ "Debug", "Release" })
toolset("clang") -- Explicitly use Clang

project("engine")
kind("SharedLib")
language("C")
targetdir("bin/%{cfg.buildcfg}")

files({ "engine/**.h", "engine/**.c" })

includedirs({
	"engine/src", -- Use relative include
	"/usr/include",
	"/usr/include/GL",
	"/usr/include/GLFW",
	"/usr/include/cglm",
})

libdirs({ "/usr/lib" })
links({ "GL", "GLEW", "glfw", "m" })

filter("system:linux")
buildoptions({ "-Wall" })
pic("On")

filter("configurations:Debug")
defines({ "DEBUG" })
symbols("On")

filter("configurations:Release")
defines({ "NDEBUG" })
optimize("On")

project("test")
kind("ConsoleApp")
language("C")
targetdir("bin/%{cfg.buildcfg}")

files({ "testbed/**.h", "testbed/**.c" })

includedirs({
	"engine/src", -- Include engine headers
	"/usr/include",
	"/usr/include/GL",
	"/usr/include/GLFW",
	"/usr/include/cglm",
})

libdirs({ "/usr/lib" })
links({ "GL", "GLEW", "glfw", "m", "engine" })

filter("system:linux")
buildoptions({ "-Wall" })

filter("configurations:Debug")
defines({ "DEBUG" })
symbols("On")

filter("configurations:Release")
defines({ "NDEBUG" })
optimize("On")

workspace("KhoPhee")
configurations({ "Debug", "Release" })
toolset("clang") -- Explicitly use Clang

project("engine")
kind("SharedLib")
language("C")
targetdir("bin/%{cfg.buildcfg}")

defines({ "KEXPORT", "KLINUX" })

files({ "engine/src/**.h", "engine/src/**.c" })

includedirs({
	"engine/src", -- Use relative include
	"/usr/include",
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

project("testbed")
kind("ConsoleApp")
language("C")
targetdir("bin/%{cfg.buildcfg}")

files({ "testbed/**.h", "testbed/**.c" })

includedirs({
	"engine/src", -- Include engine headers
})

libdirs({ "/usr/lib" })
links({ "engine", "X11", "X11-xcb", "xcb" })

filter("system:linux")
buildoptions({ "-Wall" })

filter("configurations:Debug")
defines({ "DEBUG" })
symbols("On")

filter("configurations:Release")
defines({ "NDEBUG" })
optimize("On")

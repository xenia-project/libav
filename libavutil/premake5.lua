local libav_root = "../"
project("libavutil")
  uuid("B07CEFBA-663D-4505-AD49-0AC1FCAFB35C")
  buildoptions({
	"/wd4018", -- signed/unsigned mismatch
	"/wd4028", -- formal parameter 3 different from declaration
	"/wd4090", -- different const qualifiers
	"/wd4101", -- unreferenced local variable
	"/wd4146", -- unary minus operator applied to unsigned type, result still unsigned
	"/wd4244", -- conversion 'x' to 'x', possible loss of data
	"/wd4267", -- 'initializing': conversion from 'x' to 'x', possible loss of data
	"/wd4305", -- 'initializing': truncation from 'x' to 'x'
  })
  defines({
	"_USE_MATH_DEFINES", -- For M_PI/etc
  })
  kind("StaticLib")
  language("C++")
  includedirs({
	libav_root,
  })
  local_platform_files()
  files({
	"**/cpu.*",
	"x86/*.c",
	"x86/*.h",
  })
local libav_root = "../"
project("libavutil")
  uuid("B07CEFBA-663D-4505-AD49-0AC1FCAFB35C")
  defines({
    "_USE_MATH_DEFINES", -- For M_PI/etc
  })
  kind("StaticLib")
  language("C")
  includedirs({
    libav_root,
  })
  files({
    "*.c",
    "*.h",
    "x86/*.c",
    "x86/*.h",
  })
  filter("platforms:Windows")
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
  filter("platforms:Linux")
    buildoptions({
      "-Wno-error=incompatible-pointer-types-discards-qualifiers",
      "-Wno-error=switch",
      "-Wno-error=incompatible-pointer-types",
      "-Wno-error=logical-op-parentheses",
      "-Wno-error=pointer-sign",
      "-Wno-error=parentheses",
    })

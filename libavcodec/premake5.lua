local libav_root = "../"
project("libavcodec")
  uuid("9DB2830C-D326-48ED-B4CC-08EA6A1B7272")
  files({
    "**/fdct.*",
    "**/fdctdsp_init*.c",
    "**/fft.h",
    "**/fft_init*.c",
    "avfft.h",
    "avpacket.c",
    "bitstream.c",
    "bitstream_filter.c",
    "codec_desc.c",
    "fft_float.c",
    "get_bits.h",
    "imgconvert.c",
    "log2_tab.c",
    "mathtables.c",
    "mdct_float.c",
    "options.c",
    "parser.c",
    "put_bits.h",
    "pthread.c",
    "pthread_*",
    "qsv_api.c",
    "sinewin.c",
    "utils.c",
    "wmaprodata.h",
    "wma.*",
    "wma_common.*",
    "wma_freqs.*",
    "xma2dec.c",
    "xma2dec.h",
  })
  defines({
    "_USE_MATH_DEFINES", -- For M_PI/etc
  })
  kind("StaticLib")
  language("C")
  links({
    "libavutil",
  })
  includedirs({
    libav_root,
  })
  filter("platforms:Windows")
    buildoptions({
      "/wd4013", -- undefined; assuming extern returning int
      "/wd4018", -- signed/unsigned mismatch
      "/wd4028", -- formal parameter 3 different from declaration
      "/wd4047", -- 'initializing': 'x' differs in levels of indirection from 'x'
      "/wd4087",
      "/wd4089", -- different types in actual parameter x, formal parameter x
      "/wd4090", -- different const qualifiers
      "/wd4101", -- unreferenced local variable
      "/wd4113",
      "/wd4133", -- incompatible types
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
      "-Wno-error=pointer-sign",
      "-Wno-error=parentheses",
    })

#if defined(_WIN32)
#include "config_win.h"
#elif defined(__linux)
#include "config_lin.h"
#else
#error "no config"
#endif

#pragma once
#if defined(_WIN32)
#include <windows.h>
typedef DXGI_RATIONAL ovrRational;
#else
#error "Unsupported Platform."
#endif

typedef struct ovrSizei_ {
  int w, h;
} ovrSizei;

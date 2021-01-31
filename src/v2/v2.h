#pragma once

#define V2_INTERNAL_WIDTH 640
#define V2_INTERNAL_HEIGHT 480

extern void v2Init(const char* appName, int magnification);
extern void v2Cleanup();

extern int v2MainLoop();
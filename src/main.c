#include <stdio.h>
#include <raylib.h>

#include "v2/v2.h"
#include "v2/scene.h"

#include "intro.h"

int main()
{
    // initialization (no touchy!!!!)
    SetTraceLogLevel(LOG_FATAL);
    v2Init("YO YO YO!", 2);

    // register scenes here
    v2RegisterScene(0, &IntroExport);

    // main loop
    v2MainLoop();

    v2UnloadScene(); // unload loaded scene at end of program
    v2Cleanup();
    return 0;
}
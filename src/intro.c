#include "intro.h"
#include "v2/v2.h"
#include "v2/utility.h"

#include <time.h>

static Font f1;

static void Init()
{
    HideCursor();
    f1 = LoadFont("fon/bios_font.ttf");
}

static void Update()
{
    float delta = GetFrameTime() * 1000; // m/s
}

static void Draw()
{
    ClearBackground(BLACK);
    v2DrawCenteredTextH(f1, "@snail / 2020", V2_INTERNAL_HEIGHT / 2 - 8, WHITE, 8);
}

static void Unload()
{
    UnloadFont(f1);
}

v2Scene IntroExport = {
    .init = Init,
    .update = Update,
    .draw = Draw,
    .unload = Unload,
    .initialized = 0,
};
#include "v2.h"

#include <raylib.h>
#include "scene.h"

RenderTexture _v2RenderTexture;

void v2Init(const char* appName, int magnification)
{
    InitWindow(V2_INTERNAL_WIDTH * magnification, V2_INTERNAL_HEIGHT * magnification, appName);
    SetTraceLogLevel(LOG_WARNING);
    SetExitKey(0);

    _v2RenderTexture = LoadRenderTexture(V2_INTERNAL_WIDTH, V2_INTERNAL_HEIGHT);
    SetTextureFilter(_v2RenderTexture.texture, FILTER_POINT);
}

void v2Cleanup()
{
    UnloadRenderTexture(_v2RenderTexture);
    CloseWindow();
}

int v2MainLoop()
{
    while (!WindowShouldClose())
    {
        // Update
        v2UpdateScene();

        // Draw     
        BeginTextureMode(_v2RenderTexture);
            v2DrawScene();
        EndTextureMode();

        BeginDrawing();
            DrawTexturePro(_v2RenderTexture.texture,
                          (Rectangle) { 0, 0, V2_INTERNAL_WIDTH, -V2_INTERNAL_HEIGHT },
                          (Rectangle) { 0, 0, GetScreenWidth(), GetScreenHeight() },
                          (Vector2) { 0, 0 },
                          0.0f,
                          WHITE);
        EndDrawing();
    }

    return 0;
}
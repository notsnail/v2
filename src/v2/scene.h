#pragma once
#include <raylib.h>

#define V2_MAX_SCENES 8

typedef void (*_v2CallbackFunc)();

typedef struct
{
    _v2CallbackFunc init;
    _v2CallbackFunc update;
    _v2CallbackFunc draw;
    _v2CallbackFunc unload;

    int initialized;
} v2Scene;

// exports

extern void v2RegisterScene(int index, v2Scene* scene);
extern void v2BindScene(int index);
extern void v2TransitionToScene(int index);

extern void v2InitScene();
extern void v2UnloadScene();
extern void v2DrawScene();
extern void v2UpdateScene();

#include "scene.h"
#include "v2.h"
#include "utility.h"

static v2Scene* scenes[V2_MAX_SCENES]; // 8 max scenes
static int currentScene = 0;

static bool inTransition = false;
static bool initialized = false;

// exports

void v2RegisterScene(int index, v2Scene* scene)
{
    scenes[index] = scene;
    if (index == currentScene) v2InitScene();
}

void v2BindScene(int index)
{
    v2UnloadScene();
    currentScene = index;
    v2InitScene();
}

void v2TransitionToScene(int index)
{
    
}

// backend
void v2InitScene()
{
    scenes[currentScene]->init();
    scenes[currentScene]->initialized = 1;
}

void v2UnloadScene()
{
    scenes[currentScene]->unload();
    scenes[currentScene]->initialized = 0;
}

void v2DrawScene()
{
    scenes[currentScene]->draw();
}

void v2UpdateScene()
{
    scenes[currentScene]->update();
}

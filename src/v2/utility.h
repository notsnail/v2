#pragma once

#include <raylib.h>

typedef struct 
{
    int numberOfFrames;
    int frameCounter;
    
    int speed;
    int frameWidth, frameHeight;

    Rectangle spriteClips[32];
} v2Sprite;


extern void v2DrawCenteredTextH(Font font, const char* input, int y, Color color, int size);

extern void v2UpdateSprite(v2Sprite* sprite);
extern void v2DrawSprite(v2Sprite* sprite, Texture2D texture, int x, int y);

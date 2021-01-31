#include "utility.h"
#include "v2.h"

#include <string.h>

void v2DrawCenteredTextH(Font font, const char* input, int y, Color color, int size)
{
    DrawTextEx(font, input, 
            (Vector2) { (V2_INTERNAL_WIDTH / 2) - ((strlen(input) * size) / 2), y }, 
            size, 1, color);
}

void v2UpdateSprite(v2Sprite* sprite)
{
    sprite->frameCounter++;

    if ((sprite->frameCounter / sprite->speed) >= sprite->numberOfFrames)
    {
        sprite->frameCounter = 0;
    }
}

void v2DrawSprite(v2Sprite* sprite, Texture2D texture, int x, int y)
{
    DrawTexturePro(texture, sprite->spriteClips[sprite->frameCounter / sprite->speed],
                    (Rectangle) { x, y, sprite->frameWidth, sprite->frameHeight },
                    (Vector2) { 0, 0 },
                    0.0f, WHITE);
}
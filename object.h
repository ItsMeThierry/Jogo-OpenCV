#pragma once
#include "SDL2/SDL.h"
#include "texture.h"

class Object{
    protected:
        SDL_Rect* destR;
        Texture texture;
    
    public:
        Object(Texture texture);

        SDL_Rect* getDestR();

        Texture getTexture();
};
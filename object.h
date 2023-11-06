#pragma once
#include "SDL2/SDL.h"
#include "texture.h"

class Object{
    protected:
        SDL_Rect destR;
        SDL_Rect srcR;
        Texture texture;
    
    public:
        Object(Texture texture);
        void setXPos(int x);
        void setYPos(int y);

        Texture getTexture();
};
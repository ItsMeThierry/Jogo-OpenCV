#pragma once
#include "SDL2/SDL.h"
#include "texture.h"

class Object{
    protected:
        SDL_Rect* destR;
        Texture* texture;
    
    public:
        Object();
        Object(int width, int height, int u, int v, int frames);

        SDL_Rect* getDestR();

        Texture* getTexture();

        void setPos(int x, int y);
        void setSize(int x, int y);
};
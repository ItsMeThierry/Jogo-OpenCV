#pragma once

#include "game.h"
#include <string>

class TextureManager{
    public:
        static SDL_Texture* loadTexture(std::string fname, SDL_Renderer* renderer);
        
};
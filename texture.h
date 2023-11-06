#pragma once
#include "SDL2/SDL.h"
#include <string>

class Texture{
    private:
        std::string file;
        SDL_Rect* srcR;
        int frames;
        int frame;

    public:
        Texture();
        Texture(std::string file, int w, int h, int f);
        void changeToFrame(int pos);

        SDL_Rect* getSrcR();
        std::string getFileName();
};
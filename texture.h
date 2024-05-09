#pragma once
#include "SDL2/SDL.h"
#include <string>

class Texture{
    private:
        SDL_Rect* srcR;
        int frames;
        int frame;
        int anim;

    public:
        Texture();
        Texture(int width, int height, int u, int v, int f);
        void changeToFrame(int pos);
        int getFramePos();

        SDL_Rect* getSrcR();
        void changeAnim(int id);
        int getAnim();
};
#pragma once
#include "SDL2/SDL.h"

class Texture{
    private:
        std::string file;
        int width;
        int height;
        int frames;
        int frame;

    public:
        Texture();
        Texture(std::string file, int w, int h, int f);
        void changeToFrame(int pos);

        int getWidth();
        int getHeght();
};
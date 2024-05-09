#pragma once
#include "object.h"
#include "textureManager.h"
#include "SDL2/SDL.h"

class GameOver{
    private:
        SDL_Renderer *renderer;
        Object* tela;
        int c;

    public:
        GameOver();
        GameOver(SDL_Renderer *renderer);
        void start();
        void update();
        void render();
        void close();
};
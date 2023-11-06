#pragma once
#include "object.h"
#include "bedroom.h"
#include "textureManager.h"
#include "SDL2/SDL.h"
#include <vector>

class Night{
    private:
        std::vector<Object*> objetos;
        SDL_Renderer *renderer;
        int pos; //0 bedroom, 1 right door, 2 left door
        bool light;
        bool door;
        float time;

    public:
        Object* cenario;
        Night();
        Night(SDL_Renderer *renderer);
        void start();
        void update();
        void render();
        void close();
};
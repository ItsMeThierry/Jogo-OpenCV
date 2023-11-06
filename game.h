#pragma once
#include "SDL2/SDL.h"
#include "webcamManager.h"

class Game{
    private:
        bool running;
        SDL_Renderer *renderer;
        SDL_Window *window;
        SDL_Texture* roomTex;
        
    public:
        void init(bool fullscream);
        void handleEvents();
        void update();
        void render();
        void close();
        bool isRunning();
};
#pragma once
#include "SDL2/SDL.h"
#include "webcamManager.h"

class Game{
    private:
        bool running;
        SDL_Renderer *renderer;
        SDL_Window *window;
        WebcamManager *webcam;
        
    public:
        void init(bool fullscream);
        void handleEvents();
        int update();
        void render();
        void close();
        bool isRunning();
};
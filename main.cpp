#include "game.h"
#include <iostream>

using namespace std;

int main( int argc, const char** argv)
{
    //g++ main.cpp game.cpp webcamManager.cpp textureManager.cpp object.cpp bedroom.cpp night.cpp texture.cpp -o cinco_noites `pkg-config --cflags opencv4` `pkg-config --libs --static opencv4` -lSDL2 -lSDL2_image
    //g++ image.cpp -o imagens `pkg-config --cflags opencv4` `pkg-config --libs --static opencv4`
    
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;
    
    Game *game = new Game();

    game->init(false);

    while(game->isRunning()){
        frameStart = SDL_GetTicks();

        game->handleEvents();

        if(game->update() == -1){
            cout << "Erro com a webcam";
            break;
        }

        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->close();

    return 0;
}
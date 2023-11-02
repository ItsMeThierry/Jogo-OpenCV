#include "game.h"
#include "webcamManager.h"
#include <iostream>

using namespace std;

int main( int argc, const char** argv)
{
    //g++ main.cpp game.cpp webcamManager.cpp -o cinco_noites `pkg-config --cflags opencv4` `pkg-config --libs --static opencv4` -lSDL2 -pthread
    Game *game = new Game();
    WebcamManager *webcam = new WebcamManager(game);

    game->init(false);

    webcam->init();

    while(1){
        if(!game->isRunning())
            break;
        
        webcam->capture >> webcam->frame;
        webcam->detectAndDraw(webcam->frame, webcam->cascade, webcam->scale, webcam->tryflip);

        game->handleEvents();
        game->update();
        game->render();

    }

    game->close();

    delete webcam;

    return 0;
}
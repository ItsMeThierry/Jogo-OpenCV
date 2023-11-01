#include "game.h"
#include "webcamManager.h"
#include <iostream>
#include <thread>

using namespace std;

int main( int argc, const char** argv )
{
    //g++ main.cpp game.cpp webcamManager.cpp -o cinco_noites `pkg-config --cflags opencv4` `pkg-config --libs --static opencv4` -lSDL2 -pthread
    Game *game = new Game();
    WebcamManager *webcam = new WebcamManager();

    game->init(false);

    thread webcam_thread(webcam->start());

    while(game->isRunning()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->close();
    return 0;
}
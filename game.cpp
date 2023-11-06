#include "game.h"
#include "webcamManager.h"
#include "textureManager.h"
#include "night.h"
#include <iostream>

SDL_Rect destR, srcR;
WebcamManager *webcam;
Rect r;
int i = 0;

Night night;

void Game::init(bool fullscream){
    int flags = 0;

    if(fullscream){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Inicializando...\n";

        window = SDL_CreateWindow("Cinco Noites", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 848, 480, SDL_WINDOW_SHOWN);

        if(window){
            std::cout << "Abrindo janela...\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer){
            std::cout << "Renderizando janela...\n";
        }

        webcam = new WebcamManager();

        webcam->init();

        night = Night(renderer);
        night.start();

        running = true;
    } else{
        running = false;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    night.render();
    SDL_RenderPresent(renderer);
}

void Game::update(){
    webcam->capture >> webcam->frame;
    r = webcam->detectAndDraw(webcam->frame, webcam->cascade, webcam->scale, webcam->tryflip);

    destR.w = 848;
    destR.h = 480;

    srcR.w = 848;
    srcR.h = 480;

    if(r.x > 0 && r.y > 0){
        cout << r.x << " ; " << r.y << endl;

        if(r.x > 150 && i < 10){
            i++;
        } else if(r.x < 100 && i > 0){
            i--;
        }

        srcR.y = (480*i)+1;
    }
    
}

void Game::close(){
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(roomTex);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Fechando o jogo...\n";
}

bool Game::isRunning(){
    return running;
}
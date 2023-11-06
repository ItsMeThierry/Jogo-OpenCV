#include "game.h"
#include "webcamManager.h"
#include "textureManager.h"
#include "night.h"
#include <iostream>

int i;
Rect r;
Night* night;

void Game::init(bool fullscream){
    int flags = 0;

    if(fullscream){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    webcam = new WebcamManager();

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 && webcam->init() == 0){
        std::cout << "Inicializando...\n";

        window = SDL_CreateWindow("Cinco Noites", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 848, 480, SDL_WINDOW_SHOWN);

        if(window){
            std::cout << "Abrindo janela...\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer){
            std::cout << "Renderizando janela...\n";
        }

        i = 0;

        night = new Night(renderer);
        night->start();

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
    night->render();
    SDL_RenderPresent(renderer);
}

int Game::update(){
    webcam->capture >> webcam->frame;
    
    if(webcam->frame.empty()){
        return -1;
    }

    r = webcam->detectFace();

    cout << r.x << " ; " << r.y << endl;

    //night.update();
    /*
    if(r.x > 0 && r.y > 0){
        

        if(r.x > 150 && i < 13){
            i++;
        } else if(r.x < 100 && i > 0){
            i--;
        }

        //night->cenario->getTexture().changeToFrame(i);
    }
    */
    return 0;
}

void Game::close(){
    SDL_DestroyWindow(window);
    night->close();
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    delete webcam;
    std::cout << "Fechando o jogo...\n";
}

bool Game::isRunning(){
    return running;
}
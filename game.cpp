#include "game.h"
#include <iostream>

void Game::init(bool fullscream){
    int flags = 0;

    if(fullscream){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Inicializando...\n";

        window = SDL_CreateWindow("Cinco Noites", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

        if(window){
            std::cout << "Abrindo janela...\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer){
            std::cout << "Renderizando janela...\n";
        }

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

    SDL_RenderPresent(renderer);
}

void Game::update(){
}

void Game::close(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Fechando o jogo...\n";
}

bool Game::isRunning(){
    return running;
}
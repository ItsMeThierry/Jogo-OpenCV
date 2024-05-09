#include "gameOver.h"

SDL_Texture *telaTex;

GameOver::GameOver(){}

GameOver::GameOver(SDL_Renderer* renderer){
    this->renderer = renderer;

    telaTex = nullptr;
}

void GameOver::start(){
    tela = new Object(848, 480, 0, 0, 12);

    telaTex = TextureManager::loadTexture("resources/images/game_over.png", renderer);
}

void GameOver::update(){
    if(c == 11){
        c = 8;
    } else{
        c++;
    }
    
    tela->getTexture()->changeToFrame(c);
}

void GameOver::render(){
    SDL_RenderCopy(renderer, telaTex, tela->getTexture()->getSrcR(), tela->getDestR());
}

void GameOver::close(){
    SDL_DestroyTexture(telaTex);
}
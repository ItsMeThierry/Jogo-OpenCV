#include "night.h"

SDL_Texture *cenarioTex;

Night::Night(SDL_Renderer *renderer){
    this->renderer = renderer;

    cenario = new Bedroom();
}

void Night::start(){
    cenarioTex = TextureManager::loadTexture("bedroom.jpg", renderer);
}

void Night::render(){
    //SDL_RenderCopy(renderer, cenarioTex, &srcR, &destR);
}
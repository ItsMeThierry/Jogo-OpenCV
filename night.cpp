#include "night.h"
#include <iostream>

SDL_Texture *cenarioTex;

Night::Night(){}

Night::Night(SDL_Renderer *renderer){
    this->renderer = renderer;

    cenario = new Bedroom();
    cenarioTex = nullptr;
}

void Night::start(){
    //cenarioTex = TextureManager::loadTexture(cenario->getTexture().getFileName(), renderer);
}

void Night::update(){
}

void Night::render(){
    //cout << cenario->getTexture().getSrcR()->w << endl;
    //SDL_RenderCopy(renderer, cenarioTex, cenario->getTexture().getSrcR(), cenario->getDestR());
}

void Night::close(){
    //SDL_DestroyTexture(cenarioTex);
}
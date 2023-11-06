#include "textureManager.h"
#include "SDL2/SDL_image.h"
#include <iostream>

SDL_Texture* TextureManager::loadTexture(const char* fname, SDL_Renderer* renderer){
    SDL_Surface* tempSurface = IMG_Load(fname);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}
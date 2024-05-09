#include "textureManager.h"
#include "SDL2/SDL_image.h"
#include <iostream>

using namespace std;

SDL_Texture* TextureManager::loadTexture(string fname, SDL_Renderer* renderer){
    SDL_Surface* tempSurface = IMG_Load(fname.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}
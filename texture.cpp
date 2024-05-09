#include "texture.h"
#include <iostream>

using namespace std;

Texture::Texture(){
}

Texture::Texture(int width, int height, int u, int v, int f){
    srcR = new SDL_Rect();
    srcR->w = width;
    srcR->h = height;
    srcR->x = u;
    srcR->y = v;
    frames = f;
    frame = 0;
    anim = 0;
}

void Texture::changeToFrame(int pos){
    srcR->y = srcR->h*pos;
    frame = pos;
}

SDL_Rect* Texture::getSrcR(){
    return srcR;
}

int Texture::getFramePos(){
    return frame;
}

void Texture::changeAnim(int id){
    srcR->x = 848*id;
    anim = id;
}

int Texture::getAnim(){
    return anim;
}
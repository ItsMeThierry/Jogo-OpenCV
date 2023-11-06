#include "texture.h"
#include <iostream>

using namespace std;

Texture::Texture(){
    file = "orange.png";
    //srcR->w = 100;
    //srcR->h = 84;
    frames = 0;
    frame = 0;
}

Texture::Texture(string file, int w, int h, int f){
    this->file = file;
    //srcR->w = w;
    //srcR->h = h;
    frames = f;
    frame = 0;
}

void Texture::changeToFrame(int pos){
    srcR->y = srcR->h*pos+1;
}

SDL_Rect* Texture::getSrcR(){
    return srcR;
}

string Texture::getFileName(){
    return file;
}
#include "object.h"
#include <iostream>

Object::Object(){}

Object::Object(int width, int height, int u, int v, int frames){
    texture = new Texture(width, height, u, v, frames);

    destR = new SDL_Rect();
    destR->w = texture->getSrcR()->w;
    destR->h = texture->getSrcR()->h;
}

SDL_Rect* Object::getDestR(){
    return destR;
}

Texture* Object::getTexture(){
    return texture;
}

void Object::setSize(int w, int h){
    destR->w = w;
    destR->h = h;
}

void Object::setPos(int x, int y){
    destR->x = x;
    destR->y = y;
}
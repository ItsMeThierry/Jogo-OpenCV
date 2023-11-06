#include "object.h"
#include <iostream>

Object::Object(Texture texture){
    this->texture = texture;

    //destR->w = texture.getSrcR()->w;
    //destR->h = texture.getSrcR()->h;
}

SDL_Rect* Object::getDestR(){
    return destR;
}

Texture Object::getTexture(){
    return texture;
}
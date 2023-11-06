#include "object.h"
#include <iostream>

Object::Object(Texture texture){
    this->texture = texture;
    
    srcR.w = texture.getWidth();
    srcR.h = texture.getHeght();

    destR.x = 0;
    destR.y = 0;
}

Texture Object::getTexture(){
    return texture;
}
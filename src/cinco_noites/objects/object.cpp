#include "object.h"

using namespace sf;

Object::Object(const char path[]){
    this->textureHandler.setTexture(path);
    this->init();
}

Object::~Object(){}

void Object::update(){}

void Object::render(RenderTarget& target){
    target.draw(this->sprite);
}

void Object::init(){
    this->sprite.setTexture(this->textureHandler.getTexture());
}

TextureHandler Object::getTextureHandler(){
    return this->textureHandler;
}
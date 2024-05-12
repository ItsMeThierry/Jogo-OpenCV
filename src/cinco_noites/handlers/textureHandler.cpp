#include <iostream>
#include "textureHandler.h"

using namespace std;
using namespace sf;

TextureHandler::TextureHandler(){
    this->frame = 0;
    this->loopAnim = false;
    this->playingAnim = false;
}

TextureHandler::~TextureHandler(){}

void TextureHandler::setFrame(int pos){
    this->frame = pos;

    this->update();
}

int TextureHandler::getFrame(){
    return this->frame;
}

void TextureHandler::nextFrame(){
    this->frame++;

    this->update();
}

void TextureHandler::update(){
    this->texRect.top = this->texRect.height*frame;
}

Texture& TextureHandler::getTexture(){
    return this->texture;
}

void TextureHandler::setTexture(const char filePath[]){
    if(!this->texture.loadFromFile(filePath)){
        cout << "[ERROR] Couldn't load: " << filePath << endl;
    }
}

void TextureHandler::setTexRect(int xPos, int yPos, int width, int height){
    this->texRect = Rect(xPos, yPos, width, height);
}

IntRect TextureHandler::getTexRect(){
    return this->texRect;
}

bool TextureHandler::isPlayingAnim(){
    return this->playingAnim;
}
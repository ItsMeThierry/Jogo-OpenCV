#include "screen.h"

using namespace sf;

Screen::Screen(){
}

Screen::~Screen(){
    delete this->background;
}

void Screen::render(RenderTarget& target){
    this->background->render(target);
}
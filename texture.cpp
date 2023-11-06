#include "texture.h"
#include <iostream>

using namespace std;

Texture::Texture(){
    file = "resources/orange.png";
    width = 100;
    height = 84;
    frames = 0;
    frame = 0;
}

Texture::Texture(string file, int w, int h, int f){
    this->file = file;
    width = w;
    height = h;
    frames = f;
    frame = 0;
}

void Texture::changeToFrame(int pos){
    frame = pos;
}
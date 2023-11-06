#include "bedroom.h"
#include <iostream>

Bedroom::Bedroom() : Object(texture){
    texture = Texture("resources/bedroom.jpg", 848, 480, 13);
}

Bedroom::~Bedroom(){}
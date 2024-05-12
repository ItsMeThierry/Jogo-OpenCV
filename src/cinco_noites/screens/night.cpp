#include "night.h"
#include <iostream>

Night::Night(){
    std::cout << "Generating Night Screen...";
    this->init();
}

Night::~Night(){}

void Night::init(){
    this->background = new Object("resources/textures/bedroom.png");

    this->webcamHandler = new WebcamHandler();
}

void Night::update(){
    int x = 0;
    int y = 0;

    this->webcamHandler->detectFace(&x, &y);

    std::cout << "X: " << x << " Y: " << y << std::endl;
}
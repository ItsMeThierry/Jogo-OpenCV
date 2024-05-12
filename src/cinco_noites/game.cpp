#include "game.h"
#include <iostream>

using namespace sf;
using namespace std;

Game::Game(){
    this->init();
}

Game::~Game(){
    delete this->window;
    delete this->screen;
}

void Game::init(){
    cout << "Starting game..." << endl;

    this->window = nullptr;

    this->videoMode.height = 480;
    this->videoMode.width = 760;

    cout << "Opening window..." << endl;

    this->window = new RenderWindow(this->videoMode, "Cinco Noites", Style::Titlebar | Style::Close);

    this->screen = new Night();
}

void Game::update(){
    while (this->window->pollEvent(e)){
        if (e.type == Event::Closed)
            this->window->close();
    }

    this->screen->update();
}

void Game::render(){
    this->window->clear();
    this->screen->render(*this->window);
    this->window->display();
}

const bool Game::running() const{
    return this->window->isOpen();
}
#include <SFML/Graphics.hpp>
#include "screens/screens.h"

#ifndef GAME_H
#define GAME_H

class Game{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event e;

        Screen* screen;

        void init();

    public:
        Game();
        virtual ~Game();

        void update();
        void render();

        const bool running() const;
};

#endif
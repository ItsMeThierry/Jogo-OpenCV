#include <SFML/Graphics.hpp>
#include <vector>
#include "../objects/object.h"

#ifndef SCREEN_H
#define SCREEN_H

class Screen{
    protected:
        Object* background;

    public:
        Screen();
        virtual ~Screen();
        virtual void init() = 0;
        virtual void update() = 0;
        void render(sf::RenderTarget& target);
};

#endif
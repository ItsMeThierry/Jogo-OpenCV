#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../handlers/textureHandler.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object{
    protected:
        sf::Sprite sprite;
        TextureHandler textureHandler;
        
        void init();
    
    public:
        Object(const char path[]);
        virtual ~Object();
        virtual void update();
        void render(sf::RenderTarget& target);

        TextureHandler getTextureHandler();
};

#endif
#include <SFML/Graphics.hpp>

#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

class TextureHandler{
    private:
        sf::Texture texture;
        sf::IntRect texRect;

        int frame;
        bool loopAnim;
        bool playingAnim;

    public:
        TextureHandler();
        ~TextureHandler();

        void nextFrame();
        void update();

        void setFrame(int pos);
        int getFrame();

        sf::Texture& getTexture();
        void setTexture(const char filePath[]);

        void setTexRect(int xPos, int yPos, int width, int height);

        sf::IntRect getTexRect();

        bool isPlayingAnim();
};

#endif
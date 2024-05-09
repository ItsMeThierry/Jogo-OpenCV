#pragma once
#include "object.h"
#include "textureManager.h"
#include "enemy.h"
#include "SDL2/SDL.h"
#include <ctime>
//#include <vector>

class Night{
    private:
        //std::vector<Object*> objetos;
        SDL_Renderer *renderer;
        Object* button;
        Object* control;
        Object* num1;
        Object* num2;
        Object* amTxt;
        Object* winTxt;
        Object* fernandoMiguel;
        Object* tapio;
        Object* paralisia;
        Enemy esposito;
        Enemy popo;
        Enemy manoel;
        int pos; //0 bedroom, 1 left door, 2 right door
        bool lLight, rLight;
        bool closing;
        bool moving;
        bool attacking;
        bool lDoor, rDoor;
        bool win;
        int c;

        std::clock_t start_time;

    public:
        Object* cenario;
        Object* lilBox;
        int cameraDir;
        bool cameraIsMoving;
        bool hide;
        int seconds;
        Night();
        ~Night();
        Night(SDL_Renderer *renderer);
        void start();
        void update();
        void render();
        void detectClick(int x, int y);
        void detectHold(int x, int y);
        void turnLight(bool isOn);
        void close();
        bool isClosing();
        bool isMoving();
        bool isLight();
        bool isLosing();
        bool isAttacking();
        int getPos();
};
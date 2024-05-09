#pragma once
#include <cstdlib>
#include <ctime>

class Enemy{
    private:
        int level; //0 desativado - 5 facil - 10 medio - 15 dificil - 20 impossivel
        int stage;
        int dir;
        bool entered;

    public:
        Enemy();
        bool tryMove();
        void chooseDir();
        void move();
        void goBack();
        void changeLevel(int i);
        int getStage();
        void resetStage();
        void attack();
        bool isAttacking();
        int getLevel();
        int getDir();
};
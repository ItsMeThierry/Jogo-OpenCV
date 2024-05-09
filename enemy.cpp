#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(){
    level = 0;
    stage = 0;
    dir = 0;
    entered = false;
}

bool Enemy::tryMove(){
    srand(time(0));

    return ((rand() % 20) + 1 <= level);
}

void Enemy::chooseDir(){
    srand(time(0));
    int x = (rand() % 2) + 1;

    if(x == 1){
        dir = 1;
    } else{
        dir = -1;
    }
}

void Enemy::move(){
    stage++;
}

void Enemy::goBack(){
    stage--;
}

void Enemy::changeLevel(int i){
    level = i;
}

int Enemy::getStage(){
    return stage;
}

void Enemy::resetStage(){
    stage = 0;
}

void Enemy::attack(){
    entered = true;
}

bool Enemy::isAttacking(){
    return entered;
}

int Enemy::getLevel(){
    return level;
}

int Enemy::getDir(){
    return dir;
}
#pragma once
#include "object.h"

class Bedroom : public Object{
    public:
        Bedroom();
        ~Bedroom();
        void setPos(int x, int y);
        void setSize(int x, int y);
};
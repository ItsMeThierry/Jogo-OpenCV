#include "screen.h"
#include "../handlers/webcamHandler.h"

#ifndef NIGHT_H
#define NIGHT_H

class Night : public Screen{
    private:
        WebcamHandler* webcamHandler;

    public:
        Night();
        virtual ~Night();

        void init();
        void update();
};

#endif
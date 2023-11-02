#pragma once
#include "game.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

using namespace std;
using namespace cv;

class WebcamManager{
    private:
        Game *game;

    public:
        VideoCapture capture;
        Mat frame;
        bool tryflip;
        CascadeClassifier cascade;
        double scale;
        string cascadeName;
        
        WebcamManager(Game *game);
        ~WebcamManager();
        int init();
        void detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale, bool tryflip);
};
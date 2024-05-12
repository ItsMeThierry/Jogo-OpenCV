#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

using namespace std;
using namespace cv;

#ifndef WEBCAMHANDLER_H
#define WEBCAMHANDLER_H

class WebcamHandler{
    private:
        VideoCapture capture;
        Mat frame;
        bool tryflip;
        CascadeClassifier cascade;
        double scale;
        string cascadeName;
        
    public:
        WebcamHandler();
        ~WebcamHandler();
        
        int init();
        void detectFace(int* x, int* y);
};

#endif
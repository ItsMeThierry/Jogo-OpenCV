#pragma once
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

using namespace std;
using namespace cv;

class WebcamManager{
    private:
        string cascadeName;
    public:
        int start();
        void detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale, bool tryflip);
};
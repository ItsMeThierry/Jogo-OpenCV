#include "webcamHandler.h"
#include <iostream>

using namespace std;
using namespace cv;

WebcamHandler::WebcamHandler(){
    this->init();
}

int WebcamHandler::init(){
    cascadeName = "resources/opencv/haarcascade_frontalface_default.xml";

    scale = 2; // usar 1, 2, 4.

    if (scale < 1)
        scale = 1;
    tryflip = true;

    if (!cascade.load(cascadeName)) {
        cerr << "ERROR: Could not load classifier cascade: " << cascadeName << endl;
        return -1;
    }

    if(!capture.open(0)) // para testar com a webcam
    {
        cout << "Camera não detectada" << endl;
        return 1;
    }

    if(capture.isOpened()) {
        cout << "Captura esta iniciando" << endl;
    }

    return 0;
}

void WebcamHandler::detectFace(int* x, int* y)
{
    Mat smallImg, gray;
    Scalar color = Scalar(255,0,0);
    double fx = 1 / scale;

    resize(frame, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);

    if(tryflip){
        flip(smallImg, smallImg, 1);
    }
        

    cvtColor(smallImg, gray, COLOR_BGR2GRAY);
    equalizeHist(gray, gray);

    vector<Rect> faces;

    cascade.detectMultiScale(gray, faces, 1.3, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |CASCADE_SCALE_IMAGE,
        Size(40, 40));
    
    if(faces.size() == 0){
        *x = -1;
        *y = -1;
    } else{
        *x = faces[0].x;
        *y = faces[0].y;
    }

    //cout << "X: " << *x << " Y: " << *y << endl;
}
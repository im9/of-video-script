//
//  ofVideoScript.hpp
//  ofVideoScript
//
//  Created by tn on 2017/03/14.
//
//

#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

class VideoScript {
private:
    ofxTrueTypeFontUC font;
    
public:
    // init
    VideoScript();
    void setup();
    void update(int ptnIdx);
    void draw(int ptnIdx);
    
    void showMessage(string msg = "", string soundPath = "", string moviePath = "");
    void showInfo(float startTime, float endTime, float timer, int patternIdx);
    Boolean check(float startTime, float endTime, float timer, int delay, int ptnCnt);
    
    
    float getStartTime();
    float getEndTime();
    float getTimer();
    int getIndex();
    void setIndex(int num);
    int getPtnNo();
    void setPtnNo();
    
    // timer
    float startTime; // store when we start time timer
    float endTime; // when do want to stop the timer
    float timer;
    float tmpTime;

    // index
    int idx;
    int ptnNo;
    
    // window
    int width = 1280;
    int height = 720;
//    int camWidth = ofGetWidth();
//    int camHeight = ofGetHeight();
    float vidVols[2] = {
        0.5, 0.5
    };
    
    char titles[7][32] = {
        "Title 1", // script.1
        "Title 2", // script.2
    };
    
    // flugs
    Boolean isMessge = false;
    
    // voice
    ofSoundPlayer sound;
    Boolean isLoadedSound;
    
    // movie
    ofVideoPlayer video;
    Boolean isLoadedVideo;
    
    // effect
    ofFbo myFbo;
};

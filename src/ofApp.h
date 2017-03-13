#pragma once

#include "ofMain.h"
#include "ofVideoScript.h"

class ofApp : public ofBaseApp{

public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    // objects
    ofTrueTypeFont  font;
    
    // effect
    ofFbo myFbo;
    
    // timer
    Boolean isStart = false;
    float startTime; // store when we start time timer
    float endTime; // when do want to stop the timer
    float timer;
    
    // window
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    // message
    VideoScript msg;
    int ptnCnt;
    int ptnNo;
    
    // script.1
    char words[13][100] = {
        "", // 0
        "one", // 1
        "two", // 2
        "three", // 3
        "done", // 4
        "" // 5
    };
    int pattern[26] = {
        0,
        0, 1, 0, 2, 0, 3, 0, 4, 0, 5,
        0,
    };
    int timeKeep[26] = {
        5,
        3, 4, 3, 4, 3, 4, 3, 5, 3, 2,
        2,
    }; // sec
    
    // script.2
    char words2[19][100] = {
        "", // 0
        "three", // 1
        "two", // 2
        "one", // 3
        "fin", // 4
        "" // 18
    };
    int pattern2[38] = {
        0,
        0, 1, 0, 2, 0, 3, 0, 4, 0, 5,
        0,
    };
    int timeKeep2[38] = {
        5,
        3, 4, 3, 4, 3, 4, 3, 5, 3, 2,
        2,
    }; // sec
};

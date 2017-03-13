#include "ofApp.h"
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

//--------------------------------------------------------------
void ofApp::setup(){
    ofHideCursor();
    #ifdef __APPLE__
      CGDisplayHideCursor(NULL);
    #endif

    // init color
    ofBackground(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    int idx = msg.getIndex();
    msg.update(idx);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // message
    float startTime = msg.getStartTime(); // store when we start time timer
    float endTime = msg.getEndTime(); // when do want to stop the timer
    float timer = msg.getTimer();
    int idx = msg.getIndex();
    
    // params
    int ptnNo = msg.getPtnNo();
    int ptnIdx, delay;
    string w;
    switch (ptnNo) {
        case 1:
            ptnIdx = pattern[idx];
            delay = timeKeep[idx];
            w = words[ptnIdx];
            ptnCnt = ARRAY_LENGTH(pattern);
            break;
        case 2:
            ptnIdx = pattern2[idx];
            delay = timeKeep2[idx];
            w = words2[ptnIdx];
            ptnCnt = ARRAY_LENGTH(pattern2);
            break;
        default:
            break;
    }
    
    string soundPath = "";
    string moviePath = "";
    if(ptnIdx){
        soundPath = "sounds/" + ofToString(ptnNo) + "_" + ofToString(ptnIdx) + ".wav";
        moviePath = "movies/" + ofToString(ptnNo) + "_" + ofToString(ptnIdx) + ".mp4";
    }
    msg.draw(idx);
    msg.showMessage(w, soundPath, moviePath);
    
    msg.check(startTime, endTime, timer, delay, ptnCnt);
    // msg.showInfo(startTime, endTime, timer, ptnIdx);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//
//  ofVideoScript.cpp
//  ofVideoScript
//
//  Created by tn on 2017/03/14.
//
//

#include "ofVideoScript.h"


VideoScript::VideoScript(){
    //  timer
    startTime = ofGetElapsedTimeMillis();  // get the start time
    endTime = 5000; // in milliseconds
    tmpTime = 0;
    idx = 0;
    setPtnNo();
    
    //  load font
    int fontSize = width / 40;
    font.loadFont("font/Meiryo.ttf", static_cast<int>(fontSize));
    ofEnableAlphaBlending();

    // init camera
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // init sound
    sound.setLoop(false);
    sound.setMultiPlay(true);
    
    string sPath = "sounds/" + ofToString(ptnNo) + "_1.wav";
    sound.loadSound(sPath);
    sound.setVolume(0.5);
    isLoadedSound = false;
    
    // init video
    string vPath;
    vPath = "movies/" + ofToString(ptnNo) + "_1.mp4";
    video.loadMovie(vPath);
    video.setLoopState(OF_LOOP_NONE);
    video.setVolume(vidVols[ptnNo-1]);
    video.play();
    isLoadedVideo = true;

}

//--------------------------------------------------------------
void VideoScript::setup(){
}

void VideoScript::update(int ptnIdx){
    // video
    video.update();
    
    if(video.isFrameNew()){
        // video effect
    }
}

void VideoScript::draw(int ptnIdx){
    // switch ptnIdx drow effect

    // video
    myFbo.begin();
    video.draw(0, 0, width, height);
    myFbo.end();

    // my effect

    myFbo.draw(0, 0);
    
    // script space
    ofSetColor(10, 10, 10);
    ofRect(0, height - 10, width, height / 5);
}

//--------------------------------------------------------------
void VideoScript::showMessage(string msg, string soundPath, string moviePath) {
    // title
    if(1 == idx && idx < 3){
        ofSetColor(255);
        string title = titles[ptnNo - 1];
        float t = font.stringWidth(title);
        int posX = width / 2 - t / 2, posY = height / 2;
        ofSetColor(55, 55, 55);
        for (int y = -1; y < 2; y++) {
            for (int x = -2; x < 2; x++) {
                font.drawString(title, posX + x, posY + y);
            }
        }
        ofSetColor(255, 255, 255);
        font.drawString(title, posX, posY);
    }
    
    // message
    int cnt = msg.size() / 2;
    ofSetColor(255);
    
    float w = font.stringWidth(msg);
    
    int posX = width / 2 - w / 2, posY = height - 30;
    ofSetColor(20, 20, 20);
    for (int y = -1; y < 2; y++) {
        for (int x = -2; x < 2; x++) {
            font.drawString(msg, posX + x, posY + y);
        }
    }
    
    ofSetColor(255, 255, 255);
    font.drawString(msg, posX, posY);
    // load sound
    if (isLoadedSound) {
        bool isPlaying = sound.getIsPlaying();
        if (!isPlaying && soundPath != ""){
            ofFile sfile(ofToDataPath(soundPath));
            bool isSoundFlg = sfile.exists();
            if(isSoundFlg){
                sound.loadSound(soundPath);
                sound.play();
                isLoadedSound = false;
            }
        }
    }
    // load movie
    if (isLoadedVideo && idx != 2) {
        ofFile vfile(ofToDataPath(moviePath));
        if (moviePath != ""){
            bool isVideoFlg = vfile.exists();
            if (isVideoFlg) {
                video.loadMovie(moviePath);
                video.play();
                isLoadedVideo = false;
            }
        }
    }
}


Boolean VideoScript::check(float startTime, float endTime, float timer, int delay, int ptnCnt){
    int delayTime = delay * 1000;
    if ((timer - tmpTime) > delayTime && idx < ptnCnt) {
        tmpTime = timer;
        idx++;
        isLoadedSound = true;
        isLoadedVideo = true;
        
        if (idx >= ptnCnt) {
            idx = 0;
            setPtnNo();
            
            string vidPath;
            vidPath = "movies/" + ofToString(ptnNo) + "_1.mp4";
            video.loadMovie(vidPath);
            video.setVolume(vidVols[ptnNo-1]);
            video.play();
            
            return false;
        }
    }
    return true;
}

void VideoScript::showInfo(float startTime, float endTime, float timer, int patternIdx){
    // some information about the timer
    string  info  = "FPS:        "+ofToString(ofGetFrameRate(),0)+"\n";
    info += "Start Time: "+ofToString(startTime, 1)+"\n";
    info += "End Time:   "+ofToString(endTime/1000.0, 1)+" seconds\n";
    info += "Timer:      "+ofToString(timer/1000.0, 1)+" seconds\n";
    info += "tmpTime:    "+ofToString(tmpTime/1000.0, 1)+" seconds\n";
    info += "index:      "+ofToString(idx)+"\n";
    info += "patternIdx:      "+ofToString(patternIdx)+"\n";
    info += "ptnNo:      "+ofToString(ptnNo)+"\n";
    ofSetColor(100, 100, 100);
    ofDrawBitmapString(info, 20, 20);
}

//--------------------------------------------------------------
float VideoScript::getStartTime(){
    return startTime;
}

float VideoScript::getEndTime(){
    return endTime;
}

float VideoScript::getTimer(){
    return ofGetElapsedTimeMillis() - startTime;
}

int VideoScript::getIndex() {
    return idx;
}

void VideoScript::setIndex(int num) {
    idx = num;
}

int VideoScript::getPtnNo() {
    return ptnNo;
}

void VideoScript::setPtnNo() {
    if(ptnNo <  2){
        ptnNo++;
    } else {
        ptnNo = 1;
    }
}

#pragma once

#include "ofxState.h"
#include "ofxISF.h"
#include "SharedData.h"
#include "ofApp.h"

class StISFPlasmaSarkle : public itg::ofxState<SharedData> {
public:
    virtual void setup();
    void update();
    void draw();
    void stateExit();
    void stateEnter();
    string getName();
    
    string name;
    ofApp *app;
    ofxISF::Shader *isf;
};
#include "StISFRGBRipple.hpp"

void StISFRGBRipple::setup(){
    name = "StISFRGBRipple";
    app = ((ofApp*)ofGetAppPtr());
}

void StISFRGBRipple::update(){
    isf->setUniform<float>("rippleSpeed", ofMap(app->p1, 0, 1, 1, 2));
    isf->update();
}

void StISFRGBRipple::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFRGBRipple::stateExit(){
    
}

void StISFRGBRipple::stateEnter(){
    isf = new ofxISF::Shader();
    isf->setup(1920/2, 1080/2, GL_RGB32F);
    isf->load("ISF/RGBRipple.fs");
}

string StISFRGBRipple::getName(){
    return name;
}
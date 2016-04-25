#include "StISFNoiseFlower.hpp"

void StISFNoiseFlower::setup(){
    name = "StISFNoiseFlower";
    app = ((ofApp*)ofGetAppPtr());
}

void StISFNoiseFlower::update(){
    isf->setUniform<float>("zoom", ofMap(app->p1, 0.0, 1.0, 0.1, 1.0));
    isf->update();
}

void StISFNoiseFlower::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFNoiseFlower::stateExit(){
    
}

void StISFNoiseFlower::stateEnter(){
    isf = new ofxISF::Shader();
    isf->setup(1920/2, 1080/2, GL_RGB32F);
    isf->load("ISF/NoiseFlower.fs");
}

string StISFNoiseFlower::getName(){
    return name;
}
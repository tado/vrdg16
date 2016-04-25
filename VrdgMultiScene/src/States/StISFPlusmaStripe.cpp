#include "StISFPlusmaStripe.hpp"

void StISFPlusmaStripe::setup(){
    name = "StISFPlusmaStripe";
    app = ((ofApp*)ofGetAppPtr());
    
    isf = new ofxISF::Shader();
    isf->setup(1920/2, 1080/2, GL_RGB32F);
    isf->load("ISF/PlusmaStripe.fs");
}

void StISFPlusmaStripe::update(){
    isf->setUniform<float>("weveDepth", ofMap(app->p1, 0.0, 1.0, 0.0, 1.0));
    isf->setUniform<float>("colorShift", ofMap(app->p2, 0.0, 1.0, 0.0, 1.0));
    isf->update();
}

void StISFPlusmaStripe::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFPlusmaStripe::stateExit(){
    
}

void StISFPlusmaStripe::stateEnter(){

}

string StISFPlusmaStripe::getName(){
    return name;
}
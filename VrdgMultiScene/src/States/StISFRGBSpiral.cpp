#include "StISFRGBSpiral.hpp"

void StISFRGBSpiral::setup(){
    name = "StISFRGBSpiral";
    app = ((ofApp*)ofGetAppPtr());
    
    isf = new ofxISF::Shader();
    isf->setup(ofGetWidth()/2, ofGetHeight()/2, GL_RGB32F);
    isf->load("ISF/RGBSpiral.fs");
}

void StISFRGBSpiral::update(){
    isf->setUniform<float>("mouseX", ofMap(app->p1, 0.0, 1.0, -2.0, 2.0));
    isf->setUniform<float>("mouseY", ofMap(app->p2, 0.0, 1.0, -2.0, 2.0));
    isf->update();
}

void StISFRGBSpiral::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFRGBSpiral::stateExit(){
    
}

void StISFRGBSpiral::stateEnter(){
    
}

string StISFRGBSpiral::getName(){
    return name;
}
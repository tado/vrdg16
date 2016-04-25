#include "StISFRGBWater.hpp"

void StISFRGBWater::setup(){
    name = "StISFRGBWater";
    app = ((ofApp*)ofGetAppPtr());
    
    isf = new ofxISF::Shader();
    isf->setup(1920/2, 1080/2, GL_RGB32F);
    isf->load("ISF/RGB Water.fs");
}

void StISFRGBWater::update(){
    isf->setUniform<float>("distort", ofMap(app->p1, 0, 1, 1, 2));
    isf->update();
}

void StISFRGBWater::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFRGBWater::stateExit(){
    
}

void StISFRGBWater::stateEnter(){

}

string StISFRGBWater::getName(){
    return name;
}
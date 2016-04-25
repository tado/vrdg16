#include "StISFLightTunnel.hpp"

void StISFLightTunnel::setup(){
    name = "StISFLightTunnel";
    app = ((ofApp*)ofGetAppPtr());
}

void StISFLightTunnel::update(){
    isf->setUniform<float>("shifth", ofMap(app->p1, 0, 1, -0.8, 0.8));
    isf->setUniform<float>("shiftv", ofMap(app->p2, 0, 1, -0.8, 0.8));
    isf->update();
}

void StISFLightTunnel::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFLightTunnel::stateExit(){
    
}

void StISFLightTunnel::stateEnter(){
    isf = new ofxISF::Shader();
    isf->setup(1920/2, 1080/2, GL_RGB32F);
    isf->load("ISF/LightTunnel.fs");
}

string StISFLightTunnel::getName(){
    return name;
}
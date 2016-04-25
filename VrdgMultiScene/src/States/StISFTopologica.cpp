#include "StISFTopologica.hpp"

void StISFTopologica::setup(){
    name = "StISFTopologica";
    app = ((ofApp*)ofGetAppPtr());
}

void StISFTopologica::update(){
    isf->setUniform<float>("noiseVal", app->p1);
    isf->setUniform<float>("mouseY", app->p2);
    isf->update();
}

void StISFTopologica::draw(){
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
}

void StISFTopologica::stateExit(){
    
}

void StISFTopologica::stateEnter(){
    isf = new ofxISF::Shader();
    isf->setup(1920/2, 1080/2, GL_RGB32F);
    isf->load("ISF/Topologica.fs");
    //isf->setImage(app->blackmagic->colorTexture);
}

string StISFTopologica::getName(){
    return name;
}
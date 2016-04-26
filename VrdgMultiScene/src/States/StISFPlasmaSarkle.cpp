#include "StISFPlasmaSarkle.hpp"

void StISFPlasmaSarkle::setup(){
    name = "StISFPlasmaSarkle";
    app = ((ofApp*)ofGetAppPtr());
    
    isf = new ofxISF::Shader();
    isf->setup(ofGetWidth()/2, ofGetHeight()/2, GL_RGB32F);
    isf->load("ISF/PlasmaSarkle.fs");
}

void StISFPlasmaSarkle::update(){
    isf->setUniform<float>("rotateStrength", ofMap(app->p1, 0.0, 1.0, 0.0, 10.0));
    isf->update();
}

void StISFPlasmaSarkle::draw(){
    app->post.begin();
    ofSetColor(255);
    isf->draw(0, 0, ofGetWidth(), ofGetHeight());
    app->post.end();
}

void StISFPlasmaSarkle::stateExit(){
    
}

void StISFPlasmaSarkle::stateEnter(){

}

string StISFPlasmaSarkle::getName(){
    return name;
}
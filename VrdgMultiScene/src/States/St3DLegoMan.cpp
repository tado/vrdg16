#include "St3DLegoMan.hpp"

void St3DLegoMan::setup(){
    name = "St3DLegoMan";
    app = ((ofApp*)ofGetAppPtr());
    camrot = ofVec3f(0, 0, 0);
    cam.setFov(100);
    cam.setDistance(600);
    
    model.loadModel("obj/lego/LEGO_Man.obj");
    model.setScaleNormalization(true);
    model.setPosition(0, 500, 0);
    camrot.z = 180;
}

void St3DLegoMan::update(){
    camrot.x += ofMap(app->p1, 0, 1, -30, 30);
    camrot.y += ofMap(app->p2, 0, 1, -30, 30);
    camrot.z += ofMap(app->p3, 0, 1, -30, 30);
}

void St3DLegoMan::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255);
    ofEnableDepthTest();
    cam.begin();
    ofRotateX(camrot.x);
    ofRotateY(camrot.y);
    ofRotateZ(camrot.z);
    light.enable();
    model.drawFaces();
    light.disable();
    cam.end();
    ofDisableDepthTest();
}

void St3DLegoMan::stateExit(){
    ofDisableLighting();
}

void St3DLegoMan::stateEnter(){
    ofEnableLighting();
    light.setSpotlight();
    light.setPosition(40, 40, 1000);
    light.setAmbientColor(ofFloatColor(0.2, 0.2, 1.0));
    light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0, 2.0));
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
}

string St3DLegoMan::getName(){
    return name;
}
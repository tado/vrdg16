#include "StRed.hpp"

void StRed::setup(){
    name = "StRed";
    app = ((ofApp*)ofGetAppPtr());
}

void StRed::update(){
    /*
    cout << "params : "
    << app->p1 << ", "
    << app->p2 << ", "
    << app->p3 << endl;
     */
}

void StRed::draw(){
    ofBackground(255, 0, 0);
}

void StRed::stateExit(){
    
}

void StRed::stateEnter(){
    
}

string StRed::getName(){
    return name;
}
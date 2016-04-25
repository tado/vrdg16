#include "StBlue.hpp"

void StBlue::setup(){
    name = "StBlue";
    app = ((ofApp*)ofGetAppPtr());
}

void StBlue::update(){
    cout << "params : "
    << app->p1 << ", "
    << app->p2 << ", "
    << app->p3 << endl;
}

void StBlue::draw(){
    ofBackground(0, 0, 255);
}

void StBlue::stateExit(){
    
}

void StBlue::stateEnter(){
    
}

string StBlue::getName(){
    return name;
}
#include "ofApp.h"
#include "StBlank.hpp"
#include "StRed.hpp"
#include "StBlue.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    stateMachine.addState<StBlank>();
    stateMachine.addState<StRed>();
    stateMachine.addState<StBlue>();
    stateMachine.changeState("StBlank");
    
    //OSC
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress() == "/s_new"){
            if (m.getArgAsString(0) == "state") {
                switch(m.getArgAsInt(5)){
                    case 0:
                        stateMachine.changeState("StBlank");
                        break;
                    case 1:
                        stateMachine.changeState("StRed");
                        break;
                    case 2:
                        stateMachine.changeState("StBlue");
                        break;
                }
            }
            
            if (m.getArgAsString(0) == "of") {
                p1 = m.getArgAsFloat(5);
                p2 = m.getArgAsFloat(7);
                p3 = m.getArgAsFloat(9);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
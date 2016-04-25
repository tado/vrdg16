#include "ofApp.h"
#include "StBlank.hpp"
#include "StRed.hpp"
#include "StBlue.hpp"
#include "StISFTopologica.hpp"
#include "StISFRGBWater.hpp"
#include "StISFRGBRipple.hpp"
#include "StISFNoiseFlower.hpp"
#include "StISFPlasmaSarkle.hpp"
#include "StISFPlusmaStripe.hpp"
#include "StISFLightTunnel.hpp"
#include "StISFSerching.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    stateMachine.addState<StBlank>();
    stateMachine.addState<StRed>();
    stateMachine.addState<StBlue>();
    stateMachine.addState<StISFTopologica>();
    stateMachine.addState<StISFRGBWater>();
    stateMachine.addState<StISFRGBRipple>();
    stateMachine.addState<StISFNoiseFlower>();
    stateMachine.addState<StISFPlasmaSarkle>();
    stateMachine.addState<StISFPlusmaStripe>();
    stateMachine.addState<StISFLightTunnel>();
    stateMachine.addState<StISFSerching>();
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
                    case 3:
                        stateMachine.changeState("StISFTopologica");
                        break;
                    case 4:
                        stateMachine.changeState("StISFRGBWater");
                        break;
                    case 5:
                        stateMachine.changeState("StISFRGBRipple");
                        break;
                    case 6:
                        stateMachine.changeState("StISFNoiseFlower");
                        break;
                    case 7:
                        stateMachine.changeState("StISFPlasmaSarkle");
                        break;
                    case 8:
                        stateMachine.changeState("StISFPlusmaStripe");
                        break;
                    case 9:
                        stateMachine.changeState("StISFLightTunnel");
                        break;
                    case 10:
                        stateMachine.changeState("StISFSerching");
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

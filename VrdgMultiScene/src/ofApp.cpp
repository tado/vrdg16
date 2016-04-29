#include "ofApp.h"
#include "StBlank.hpp"
#include "StRed.hpp"
#include "StBlue.hpp"
#include "StISFTopologica.hpp"
#include "StISFRGBWater.hpp"
#include "StISFRGBRipple.hpp"
#include "StISFNoiseFlower.hpp"
#include "StISFPlasmaSparkle.hpp"
#include "StISFPlusmaStripe.hpp"
#include "StISFLightTunnel.hpp"
#include "StISFSerching.hpp"
#include "StISFSpiderSpectre.hpp"
#include "StISFFurSpace.hpp"
#include "StISFRGBSpiral.hpp"
#include "StISFFlyingPlane.hpp"
#include "StImageSynth.hpp"
#include "St3DHuman.hpp"
#include "St3DSkull.hpp"
#include "St3DLegoMan.hpp"
#include "St3DHand.hpp"

string stateName[20] = {
    "StBlank", "StRed", "StBlue",
    "StISFTopologica", "StISFNoiseFlower", "StISFFlyingPlane", "StISFLightTunnel",
    "StISFPlusmaStripe", "StISFRGBRipple", "StISFRGBSpiral", "StISFRGBWater",
    "StISFPlasmaSparkle", "StISFSerching", "StISFSpiderSpectre", "StISFFurSpace",
    "StImageSynth", "St3DHuman", "St3DSkull", "St3DLegoMan", "St3DHand"
};

//--------------------------------------------------------------
void ofApp::setup(){
    stateMachine.addState<StBlank>();
    stateMachine.addState<StRed>();
    stateMachine.addState<StBlue>();
    stateMachine.addState<StISFTopologica>();
    stateMachine.addState<StISFNoiseFlower>();
    stateMachine.addState<StISFFlyingPlane>();
    stateMachine.addState<StISFLightTunnel>();
    stateMachine.addState<StISFRGBWater>();
    stateMachine.addState<StISFRGBRipple>();
    stateMachine.addState<StISFRGBSpiral>();
    stateMachine.addState<StISFSpiderSpectre>();
    stateMachine.addState<StISFFurSpace>();
    stateMachine.addState<StISFSerching>();
    stateMachine.addState<StISFPlasmaSparkle>();
    stateMachine.addState<StISFPlusmaStripe>();
    stateMachine.addState<StISFSerching>();
    stateMachine.addState<StImageSynth>();
    stateMachine.addState<St3DHuman>();
    stateMachine.addState<St3DSkull>();
    stateMachine.addState<St3DLegoMan>();
    stateMachine.addState<St3DHand>();
    stateMachine.changeState("StBlank");
    
    //OSC
    receiver.setup(PORT);
    
    //Post Proeesing
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<BloomPass>()->setEnabled(false);
    post.createPass<DofPass>()->setEnabled(false);
    post.createPass<KaleidoscopePass>()->setEnabled(false);
    post.createPass<NoiseWarpPass>()->setEnabled(false);
    post.createPass<PixelatePass>()->setEnabled(false);
    post.createPass<EdgePass>()->setEnabled(false);
    post.createPass<ContrastPass>()->setEnabled(false);
    post.createPass<ConvolutionPass>()->setEnabled(false);
    post.createPass<RGBShiftPass>()->setEnabled(false);
    //post.createPass<FakeSSSPass>()->setEnabled(false);
    //post.createPass<FxaaPass>()->setEnabled(false);
    //post.createPass<VerticalTiltShifPass>()->setEnabled(false);
    //post.createPass<GodRaysPass>()->setEnabled(false);
    //post.createPass<BleachBypassPass>()->setEnabled(false);
    //post.createPass<FxaaPass>()->setEnabled(false);
    //post.createPass<GodRaysPass>()->setEnabled(false);
    //post.createPass<HorizontalTiltShifPass>()->setEnabled(false);
    //post.createPass<LimbDarkeningPass>()->setEnabled(false);
    //post.createPass<LUTPass>()->setEnabled(false);

}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress() == "/s_new"){
            if (m.getArgAsString(0) == "state") {
                stateMachine.changeState(stateName[m.getArgAsInt(5)]);
                 /*
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
                        stateMachine.changeState("StISFNoiseFlower");
                        break;
                    case 5:
                        stateMachine.changeState("StISFFlyingPlane");
                        break;
                    case 6:
                        stateMachine.changeState("StISFLightTunnel");
                        break;
                    case 7:
                        stateMachine.changeState("StISFPlasmaSparkle");
                        break;
                    case 8:
                        stateMachine.changeState("StISFRGBRipple");
                        break;
                    case 9:
                        stateMachine.changeState("StISFRGBSpiral");
                        break;
                    case 10:
                        stateMachine.changeState("StISFRGBWater");
                        break;
                    case 11:
                        stateMachine.changeState("StISFPlusmaStripe");
                        break;
                    case 12:
                        stateMachine.changeState("StISFSpiderSpectre");
                        break;
                    case 13:
                        stateMachine.changeState("StISFFurSpace");
                        break;
                    case 14:
                        stateMachine.changeState("StISFSerching");
                        break;
                    case 20:
                        stateMachine.changeState("StImageSynth");
                        break;
                    case 21:
                        stateMachine.changeState("St3DHuman");
                        break;
                    case 22:
                        stateMachine.changeState("St3DSkull");
                        break;
                    case 23:
                        stateMachine.changeState("St3DLegoMan");
                        break;
                    case 24:
                        stateMachine.changeState("St3DHand");
                        break;
                  
                }
                  */
            }
            
            if (m.getArgAsString(0) == "of") {
                p1 = m.getArgAsFloat(5);
                p2 = m.getArgAsFloat(7);
                p3 = m.getArgAsFloat(9);
            }
            
            if (m.getArgAsString(0) == "post") {
                int n = m.getArgAsInt32(5);
                if (n == 0) {
                    for (int i = 0; i < post.size(); i++) {
                        post[i]->setEnabled(false);
                    }
                } else {
                    if (n-1 < post.size()){
                        post[n-1]->setEnabled(!post[n-1]->getEnabled());
                    }
                }
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

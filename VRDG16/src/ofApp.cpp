#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    zscale = 2.0;
    //OSC
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    // update meshes
    for (int i = 0; i < imageSynths.size(); i++) {
        imageSynths[i]->update();
    }
    // osc
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress() == "/toggle"){

        }
        if(m.getAddress() == "/rotation"){
            int n = m.getArgAsInt(0);
            if (n < imageSynths.size()) {
                imageSynths[n]->rot.x = m.getArgAsInt(1);
                imageSynths[n]->rot.y = m.getArgAsInt(2);
                imageSynths[n]->rot.z = m.getArgAsInt(3);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (pressed) {
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(0, 63);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofEnableBlendMode(OF_BLENDMODE_ADD);
    } else {
        ofEnableDepthTest();
    }

    ofEnableDepthTest();
    cam.begin();
    for (int i = 0; i < imageSynths.size(); i++) {
        imageSynths[i]->draw();
    }
    cam.end();
    ofDisableDepthTest();
    ofSetColor(255);
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    vector<ofImage> draggedImages;
    if( dragInfo.files.size() > 0 ){
        // get image data
        draggedImages.assign( dragInfo.files.size(), ofImage() );
        for(unsigned int k = 0; k < dragInfo.files.size(); k++){
            draggedImages[k].load(dragInfo.files[k]);
        }
        
        float size = 500;
        //ofVec3f pos = ofVec3f(ofRandom(-size, size), ofRandom(-size, size), ofRandom(-size, size));
        ofVec3f pos = ofVec3f(0, 0, 0);
        ImageSynth *s = new ImageSynth(draggedImages[0], pos);
        s->zscale = zscale;
        imageSynths.push_back(s);
        if (imageSynths.size() > IMGNUM) {
            imageSynths.pop_front();
            //delete imageSynths[0];
        }
    }
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
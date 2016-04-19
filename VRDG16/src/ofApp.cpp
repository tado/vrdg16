#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    zscale = 0.0;
    camrot = ofVec3f(0, 0, 0);
    cam.setFov(120);
    //OSC
    receiver.setup(PORT);
    // Setup post-processing chain
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<FxaaPass>()->setEnabled(false);
    post.createPass<BloomPass>()->setEnabled(true);
    post.createPass<DofPass>()->setEnabled(false);
    post.createPass<KaleidoscopePass>()->setEnabled(false);
    post.createPass<NoiseWarpPass>()->setEnabled(false);
    //post.createPass<PixelatePass>()->setEnabled(false);
    //post.createPass<EdgePass>()->setEnabled(false);
    post.createPass<VerticalTiltShifPass>()->setEnabled(false);
    post.createPass<GodRaysPass>()->setEnabled(false);
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
            int n = m.getArgAsInt32(0);
            if (n < post.size()) post[n]->setEnabled(!post[n]->getEnabled());
        }
        if(m.getAddress() == "/rotation"){
            int n = m.getArgAsInt(0);
            if (n < imageSynths.size()) {
                imageSynths[n]->rot.x = m.getArgAsInt(1);
                imageSynths[n]->rot.y = m.getArgAsInt(2);
                imageSynths[n]->rot.z = m.getArgAsInt(3);
            }
        }
        if(m.getAddress() == "/scale"){
            int n = m.getArgAsInt(0);
            if (n < imageSynths.size()) {
                imageSynths[n]->zscale = m.getArgAsInt(1);
            }
        }
        if(m.getAddress() == "/camrot"){
            int n = m.getArgAsInt(0);
            if (n < imageSynths.size()) {
                camrot.x = m.getArgAsInt(1);
                camrot.y = m.getArgAsInt(2);
                camrot.z = m.getArgAsInt(3);
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
    post.begin(cam);
    ofRotateX(camrot.x);
    ofRotateY(camrot.y);
    ofRotateZ(camrot.z);
    for (int i = 0; i < imageSynths.size(); i++) {
        imageSynths[i]->draw();
    }
    post.end();
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
        ofVec3f pos = ofVec3f(ofRandom(-size, size), ofRandom(-size, size), ofRandom(-size, size));
        //ofVec3f pos = ofVec3f(0, 0, 0);
        ImageSynth *s = new ImageSynth(draggedImages[0], pos);
        s->zscale = zscale;
        s->rotSpeed = ofVec3f(ofRandom(-0.2, 0.2), ofRandom(-0.2, 0.2), ofRandom(-0.2, 0.2));
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
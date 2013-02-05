#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    
    frameByFrame = false;
    
    fingerMovie.loadMovie("movies/fingers.mov");
    fingerMovie.play();
    fingerMovie.setPaused(true);
    numFrames = fingerMovie.getTotalNumFrames();

}

//--------------------------------------------------------------
void testApp::update(){

    //fingerMovie.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    int currentFrame = 0;
    unsigned char * pixels = fingerMovie.getPixels();
    int nChannels = fingerMovie.getPixelsRef().getNumChannels();
    int width = fingerMovie.getWidth();
    int height = fingerMovie.getHeight();

    for (int i = 1; i < width || currentFrame != numFrames ; ++i) {
        for (int j = 1; j < height || currentFrame != numFrames; ++j) {
            
            unsigned char r = pixels[(j * width + i)*nChannels];
            unsigned char g = pixels[(j * width + i)*nChannels];
            unsigned char b = pixels[(j * width + i)*nChannels];
            
            ofSetColor(r, g, b);
            ofRect(i, j, 1, 1);
            if (currentFrame != numFrames) {
                fingerMovie.nextFrame();
                ++currentFrame;
            } else {
                fingerMovie.firstFrame();
            }
            
        }
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
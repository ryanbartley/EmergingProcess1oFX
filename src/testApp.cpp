#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    
    
    
    fingerMovie.loadMovie("movies/fingers.mov");
    fingerMovie.play();
    //fingerMovie.setPaused(true);
    
    h = fingerMovie.getHeight();
    w = fingerMovie.getWidth();
    frame = 0;
    totalFrames = fingerMovie.getTotalNumFrames();
    
    
}

//--------------------------------------------------------------
void testApp::update(){

    fingerMovie.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int y=0; y<h; y+=10) {
        for (int x=0; x<w; x+=10) {
            
            //get pixel color
            int i = (y*w+x)*3;
            int r = fingerMovie.getPixels()[i+0];
            int g = fingerMovie.getPixels()[i+1];
            int b = fingerMovie.getPixels()[i+2];
            
            ofSetColor(r, g, b);
            
            ofRect(x, y, 10, 10);
            
            if (frame <= totalFrames) {
                fingerMovie.setFrame(++frame);
            } else {
                frame = 0;
                fingerMovie.setFrame(frame);
            }
            
        }
    }

}
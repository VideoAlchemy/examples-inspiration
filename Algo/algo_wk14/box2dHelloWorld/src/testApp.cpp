#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0, 0, 0);
	
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createFloor();
	box2d.checkBounds(true);
	box2d.setFPS(30.0);
	
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
	
	box2d.update();
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for(int i=0; i<circles.size(); i++) {
		circles[i].draw();
	}
	for(int i=0; i<boxes.size(); i++) {
		boxes[i].draw();
	}	
	
	
	ofSetColor(255,255,255);
	ofDrawBitmapString("c to make circles, b to make boxes", 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	
	if(key == 'c') {
		float r = ofRandom(4, 20);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), mouseX, mouseY, r);
		circles.push_back(circle);
	}
	if(key == 'b') {
		float w = ofRandom(14, 30);	
		float h = ofRandom(14, 30);	
		ofxBox2dRect rect;
		rect.setPhysics(3.0, 0.53, 0.1);
		rect.setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(rect);
	}
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


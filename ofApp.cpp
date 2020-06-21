#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int height = 60;
	int y = ofGetHeight() * 0.5;
	
	bool flag = true;
	for (int y = height * 2; y <= ofGetHeight() - height * 2; y += height * 2) {

		int span = (flag = !flag) ? 2 : 5;
		for (int x = 60; x <= ofGetWidth() - 60; x += span) {

			auto noise_value = ofNoise(x * 0.03, y * 0.03, ofGetFrameNum() * 0.05);
			if (noise_value < 0.6) {

				ofDrawLine(x, y - height * 0.5, x, y + height * 0.5);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
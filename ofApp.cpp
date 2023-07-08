#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 240;
	int deg_span = 4;
	auto len = 120;

	for (int deg = 0; deg < 360; deg += deg_span) {

		ofPushMatrix();
		ofRotate(deg);
		ofTranslate(radius * cos(0 * DEG_TO_RAD), radius * sin(0 * DEG_TO_RAD));

		auto noise_deg = ofMap(ofNoise(cos(deg * DEG_TO_RAD) * 0.5, sin(deg * DEG_TO_RAD) * 0.5, ofGetFrameNum() * 0.008), 0, 1, -540, 540);
		ofRotateY(noise_deg);

		auto location_1 = glm::vec3((len * 0.5) * cos(0 * DEG_TO_RAD), (len * 0.5) * sin(0 * DEG_TO_RAD), 0);
		auto location_2 = glm::vec3((len * -0.5) * cos(0 * DEG_TO_RAD), (len * -0.5) * sin(0 * DEG_TO_RAD), 0);

		ofDrawLine(location_1, location_2);
		ofDrawSphere(location_1, 3);
		ofDrawSphere(location_2, 6);

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
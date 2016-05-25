#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	oscReceiver.setup(oscPort);
	ofSetEscapeQuitsApp(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	updateOscMessages();
}

void ofApp::updateOscMessages() {
	while (oscReceiver.hasWaitingMessages()) {
		ofxOscMessage m;
		oscReceiver.getNextMessage(&m);

		if (m.getAddress() == "/admin/winkey_right" &&
			m.getArgAsBool(0) == true) {
			winkeyPress(VK_RIGHT);
			ofLogWarning("Emulate Winkey+Right");
		}

		if (m.getAddress() == "/admin/winkey_left" &&
			m.getArgAsBool(0) == true) {
			winkeyPress(VK_LEFT);
			ofLogWarning("Emulate Winkey+Left");
		}

		if (m.getAddress() == "/admin/winkey_up" &&
			m.getArgAsBool(0) == true) {
			winkeyPress(VK_UP);
			ofLogWarning("Emulate Winkey+Up");
		}

		if (m.getAddress() == "/admin/winkey_1" &&
			m.getArgAsBool(0) == true) {
			winkeyPress(VkKeyScan('1'));
			ofLogWarning("Emulate Winkey+1");
		}

		if (m.getAddress() == "/admin/winkey_2" &&
			m.getArgAsBool(0) == true) {
			winkeyPress(VkKeyScan('2'));
			ofLogWarning("Emulate Winkey+2");
		}

		if (m.getAddress() == "/admin/winkey_3" &&
			m.getArgAsBool(0) == true) {
			winkeyPress(VkKeyScan('3'));
			ofLogWarning("Emulate Winkey+3");
		}

		if (m.getAddress() == "/admin/alt_escape" &&
			m.getArgAsBool(0) == true) {
			twoKeysPress(VK_LMENU, VK_ESCAPE);
			ofLogWarning("Emulate alt+escape");
		}

		if (m.getAddress() == "/admin/alt_f4" &&
			m.getArgAsBool(0) == true) {
			twoKeysPress(VK_LMENU, VK_F4);
			ofLogWarning("Emulate alt+f4");
		}


		if (m.getAddress() == "/admin/fullscreen" &&
			m.getArgAsBool(0) == true) {
			emulateKeyPress(VkKeyScan('f'));
			ofLogWarning("Emulate f");
		}

		if (m.getAddress() == "/admin/enter" &&
			m.getArgAsBool(0) == true) {
			emulateKeyPress(VK_RETURN);
			ofLogWarning("Emulate enter key");
		}

		if (m.getAddress() == "/admin/right_key" &&
			m.getArgAsBool(0) == true) {
			emulateKeyPress(VK_RIGHT);
			ofLogWarning("Emulate right key");
		}

		if (m.getAddress() == "/admin/left_key" &&
			m.getArgAsBool(0) == true) {
			emulateKeyPress(VK_LEFT);
			ofLogWarning("Emulate left key");
		}

		if (m.getAddress() == "/admin/tab_key" &&
			m.getArgAsBool(0) == true) {
			emulateKeyPress(VK_TAB);
			ofLogWarning("Emulate tab key");
		}


	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor(0, 0, 0));
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

void ofApp::twoKeysPress(int firstKey, int secondKEy) {
	keybd_event(firstKey, 0x5B, KEYEVENTF_EXTENDEDKEY | 0, 0);
	keybd_event(secondKEy, 0x20, 0, 0);
	keybd_event(secondKEy, 0x20, KEYEVENTF_KEYUP, 0);
	keybd_event(firstKey, 0x5B, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void ofApp::winkeyPress(int extraVkKey) {
	keybd_event(VK_LWIN, 0x5B, KEYEVENTF_EXTENDEDKEY | 0, 0);

	//Key press
	keybd_event(extraVkKey, 0x20, 0, 0);

	//Key release
	keybd_event(extraVkKey, 0x20, KEYEVENTF_KEYUP, 0);

	//Winkey release
	keybd_event(VK_LWIN, 0x5B, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}

void ofApp::emulateKeyPress(int vkKey) 	{
	keybd_event(vkKey, 0x20, 0, 0);
	keybd_event(vkKey, 0x20, KEYEVENTF_KEYUP, 0);
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

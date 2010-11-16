#include "ofxTweakbars.h"
#include "ofxTweakbar.h"
ofxTweakbars::ofxTweakbars() 
:visible(true)
{
	if (!TwInit(TW_OPENGL, NULL)) {
		throw TwGetLastError();
	}
	TwWindowSize(ofGetWidth(), ofGetHeight());
	setEventHandlers();
}

ofxTweakbars::~ofxTweakbars() {
	std::map<std::string, ofxTweakbar*>::iterator it = bars.begin();
	while(it != bars.end()) {
		delete it->second;
		it++;
	}
}

ofxTweakbar* ofxTweakbars::addTweakbar(std::string sName, std::string sTitle) {
	ofxTweakbar* bar = new ofxTweakbar(sName);
	bars[sName] = bar;
	return bar;
};

void ofxTweakbars::draw() {
	if(visible)
		TwDraw();
}

void ofxTweakbars::toggle() {
	visible = !visible;
}

// EVENT HANDLERS
//------------------------------------------------------------------------------
void ofxTweakbars::setEventHandlers() {
	ofAddListener(ofEvents.keyPressed,		this, &ofxTweakbars::keyPressed);
	ofAddListener(ofEvents.mouseMoved,		this, &ofxTweakbars::mouseMoved);
	ofAddListener(ofEvents.mousePressed,	this, &ofxTweakbars::mousePressed);
	ofAddListener(ofEvents.mouseReleased,	this, &ofxTweakbars::mouseReleased);
	ofAddListener(ofEvents.mouseDragged,	this, &ofxTweakbars::mouseDragged);
}

void ofxTweakbars::keyPressed(ofKeyEventArgs& rArgs) {
	TwKeyPressed(rArgs.key, TW_KMOD_NONE); // fix this!
}

void ofxTweakbars::mouseMoved(ofMouseEventArgs& rArgs) {
	TwMouseMotion(rArgs.x, rArgs.y);
}

void ofxTweakbars::mousePressed(ofMouseEventArgs& rArgs) {
	TwMouseButtonID btn = (rArgs.button == 0) ? TW_MOUSE_LEFT : TW_MOUSE_RIGHT;
	TwMouseButton(TW_MOUSE_PRESSED, btn);
}

void ofxTweakbars::mouseReleased(ofMouseEventArgs& rArgs) {
	TwMouseButtonID btn = (rArgs.button == 0) ? TW_MOUSE_LEFT : TW_MOUSE_RIGHT;
	TwMouseButton(TW_MOUSE_RELEASED, btn);
}

void ofxTweakbars::mouseDragged(ofMouseEventArgs& rArgs) {
	TwMouseMotion(rArgs.x, rArgs.y);
}

void ofxTweakbars::windowResized(ofResizeEventArgs& rArgs) {
	TwWindowSize(rArgs.width, rArgs.height);
}
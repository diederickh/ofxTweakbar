#include "ofxTweakbars.h"
#include "ofxTweakbar.h"

ofxTweakbars ofxTweakbars::instance = ofxTweakbars();

ofxTweakbars::ofxTweakbars()
:simple_storage(NULL)
,is_initialized(false)
{
}

ofxTweakbars::~ofxTweakbars() {
	std::map<std::string, ofxTweakbar*>::iterator it = ofxTweakbars::bars.begin();
	while(it != bars.end()) {
		delete it->second;
		it++;
	}
}

ofxTweakbar* ofxTweakbars::createTweakbar(std::string sName, std::string sTitle, bool bUseAutoStore) {
	if(!instance.is_initialized) {
		instance.init();
	}
	ofxTweakbar* bar = new ofxTweakbar(sName, sTitle, bUseAutoStore,&instance);

	// some defaults.
	bar	->setColor(44,44,44,180)
		->setFontSize(2);
	instance.bars[sName] = bar;
	return bar;
};

void ofxTweakbars::init() {
	visible = true;
	is_initialized = true;
	if (!TwInit(TW_OPENGL, NULL)) {
		throw TwGetLastError();
	}
	TwWindowSize(ofGetWidth(), ofGetHeight());
	setEventHandlers();

}

void ofxTweakbars::draw() {
	if(instance.visible)
		TwDraw();
}

void ofxTweakbars::toggle() {
	instance.visible = !instance.visible;
}

void ofxTweakbars::autoStore() {
	std::map<std::string, ofxTweakbar*>::iterator it = instance.bars.begin();
	while(it != instance.bars.end()) {
		if(it->second->useAutoStore()) {
			simple_storage.setBar(it->second);
			simple_storage.store();
		}
		++it;
	}
}

void ofxTweakbars::load(ofxTweakbar* pBar) {
	simple_storage.setBar(pBar);
	simple_storage.retrieve();
}

// EVENT HANDLERS
//------------------------------------------------------------------------------
void ofxTweakbars::setEventHandlers() {
	ofAddListener(ofEvents.keyPressed,		this, &ofxTweakbars::keyPressed);
	ofAddListener(ofEvents.mouseMoved,		this, &ofxTweakbars::mouseMoved);
	ofAddListener(ofEvents.mousePressed,	this, &ofxTweakbars::mousePressed);
	ofAddListener(ofEvents.mouseReleased,	this, &ofxTweakbars::mouseReleased);
	ofAddListener(ofEvents.mouseDragged,	this, &ofxTweakbars::mouseDragged);
	ofAddListener(ofEvents.windowResized,	this, &ofxTweakbars::windowResized);
}

void ofxTweakbars::keyPressed(ofKeyEventArgs& rArgs) {
	TwKeyPressed(rArgs.key, TW_KMOD_NONE); // fix this!
	// default keys (not sure if this is really user friendly.. people?)
	if(rArgs.key == '.') {
		autoStore();	
	}
	else if (rArgs.key == ',') {
		toggle();
	}
	
}

void ofxTweakbars::mouseMoved(ofMouseEventArgs& rArgs) {
	TwMouseMotion(rArgs.x, rArgs.y);
}

void ofxTweakbars::mousePressed(ofMouseEventArgs& rArgs) {
	TwMouseButtonID btn = (rArgs.button == 0) ? TW_MOUSE_LEFT : TW_MOUSE_RIGHT;
	TwMouseButton(TW_MOUSE_PRESSED, btn);
	//autoStore();
}

void ofxTweakbars::mouseReleased(ofMouseEventArgs& rArgs) {
	TwMouseButtonID btn = (rArgs.button == 0) ? TW_MOUSE_LEFT : TW_MOUSE_RIGHT;
	TwMouseButton(TW_MOUSE_RELEASED, btn);
	//autoStore();
}

void ofxTweakbars::mouseDragged(ofMouseEventArgs& rArgs) {
	TwMouseMotion(rArgs.x, rArgs.y);
	//autoStore();
}

void ofxTweakbars::windowResized(ofResizeEventArgs& rArgs) {
	TwWindowSize(rArgs.width, rArgs.height);
}
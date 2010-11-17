#include "ofxTweakbar.h"
#include "ofxTweakbarStorage.h"
ofxTweakbarStorage::ofxTweakbarStorage(ofxTweakbar* pBar)
	:bar(pBar) 
{
}

void ofxTweakbarStorage::setBar(ofxTweakbar* pBar) {
	bar = pBar;
}

ofxTweakbar* ofxTweakbarStorage::getBar() {
	return bar;
}

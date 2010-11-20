#ifndef OFXTWEAKBARBUTTONH
#define OFXTWEAKBARBUTTONH
#include "ofxTweakbarType.h"
class ofxTweakbarButton : public ofxTweakbarType {
public:
	ofxTweakbarButton(ofxTweakbar* pBar, const char* pName);
	virtual TwType getType();
};
#endif
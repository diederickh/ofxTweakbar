#ifndef OFXTWEAKBARCOLOR3FH
#define OFXTWEAKBARCOLOR3FH
#include "ofxTweakbarType.h"
class ofxTweakbarColor3f : public ofxTweakbarType {
public:
	ofxTweakbarColor3f(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual TwType getType();
};
#endif
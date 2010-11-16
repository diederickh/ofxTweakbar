#ifndef OFXTWEAKBARINTH
#define OFXTWEAKBARINTH
#include "ofxTweakbarType.h"
class ofxTweakbarInt : public ofxTweakbarType {
public:
	ofxTweakbarInt(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual TwType getType();
	int getValue();
	void setValue(int nValue);
};
#endif
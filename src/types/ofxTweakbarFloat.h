#ifndef OFXTWEAKBARFLOATH
#define OFXTWEAKBARFLOATH
#include "ofxTweakbarType.h"
class ofxTweakbarFloat : public ofxTweakbarType {
public:
	ofxTweakbarFloat(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual TwType getType();
	void setValue(float fValue);
	float getValue();
};
#endif
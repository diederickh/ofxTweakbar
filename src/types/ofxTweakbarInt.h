#ifndef OFXTWEAKBARINTH
#define OFXTWEAKBARINTH
#include "ofxTweakbarType.h"
class ofxTweakbarInt : public ofxTweakbarType {
public:
	ofxTweakbarInt(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	int getValue();
	void setValue(int nValue);
};
#endif
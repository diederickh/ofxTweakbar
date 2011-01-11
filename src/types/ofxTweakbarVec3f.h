#ifndef OFXTWEAKBARVEC3FH
#define OFXTWEAKBARVEC3FH
#include "ofxTweakbarType.h"

class ofxTweakbarVec3f : public ofxTweakbarType {
public:
	ofxTweakbarVec3f(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	float getX();
	float getY();
	float getZ();
	void setValue(float fX, float fY, float fZ);
};
#endif
#ifndef OFXTWEAKBARQUAT4FH
#define OFXTWEAKBARQUAT4FH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

class ofxTweakbarQuat4f : public ofxTweakbarType {
public:
	ofxTweakbarQuat4f(ofxTweakbar* pBar, string pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	float getX();
	float getY();
	float getZ();
	float getS();
	void setValue(float fX, float fY, float fZ, float fS);
};
#endif
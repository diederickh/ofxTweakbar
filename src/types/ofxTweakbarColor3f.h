#ifndef OFXTWEAKBARCOLOR3FH
#define OFXTWEAKBARCOLOR3FH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

class ofxTweakbarColor3f : public ofxTweakbarType {
public:
	ofxTweakbarColor3f(ofxTweakbar* pBar, string pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	float getX();
	float getY();
	float getZ();
	void setValue(float fX, float fY, float fZ);
};
#endif
#ifndef OFXTWEAKBARFLOATH
#define OFXTWEAKBARFLOATH
#include "ofxTweakbarType.h"

#include <string>
using namespace std;

class ofxTweakbarFloat : public ofxTweakbarType {
public:
	ofxTweakbarFloat(ofxTweakbar* pBar, string pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	void setValue(float fValue);
	float getValue();
};
#endif
#ifndef OFXTWEAKBARINTH
#define OFXTWEAKBARINTH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

class ofxTweakbarInt : public ofxTweakbarType {
public:
	ofxTweakbarInt(ofxTweakbar* pBar, string pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	int getValue();
	void setValue(int nValue);
};
#endif
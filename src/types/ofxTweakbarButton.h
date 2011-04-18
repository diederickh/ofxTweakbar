#ifndef OFXTWEAKBARBUTTONH
#define OFXTWEAKBARBUTTONH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

class ofxTweakbarButton : public ofxTweakbarType {
public:
	ofxTweakbarButton(ofxTweakbar* pBar, string pName);
	virtual OFX_TW_TYPE getType();
};
#endif
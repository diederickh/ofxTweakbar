#ifndef OFXTWEAKBARSEPARATORH
#define OFXTWEAKBARSEPARATORH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

class ofxTweakbarSeparator : public ofxTweakbarType {
public:
	ofxTweakbarSeparator(ofxTweakbar* pBar, string pName);
	virtual OFX_TW_TYPE getType();
};
#endif
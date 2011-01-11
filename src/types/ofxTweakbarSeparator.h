#ifndef OFXTWEAKBARSEPARATORH
#define OFXTWEAKBARSEPARATORH
#include "ofxTweakbarType.h"
class ofxTweakbarSeparator : public ofxTweakbarType {
public:
	ofxTweakbarSeparator(ofxTweakbar* pBar, const char* pName);
	virtual OFX_TW_TYPE getType();
};
#endif
#ifndef OFXTWEAKBARBOOLH
#define OFXTWEAKBARBOOLH
#include "ofxTweakbarType.h"
class ofxTweakbarBool : public ofxTweakbarType {
public:
	ofxTweakbarBool(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual TwType getType();
	bool getValue();
	void setValue(bool bValue);
};
#endif
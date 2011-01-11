#ifndef OFXTWEAKBARBOOLH
#define OFXTWEAKBARBOOLH
#include "ofxTweakbarType.h"
class ofxTweakbarBool : public ofxTweakbarType {
public:
	ofxTweakbarBool(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	bool getValue();
	void setValue(bool bValue);
};
#endif
#ifndef OFXTWEAKBARBOOLH
#define OFXTWEAKBARBOOLH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

class ofxTweakbarBool : public ofxTweakbarType {
public: 
	ofxTweakbarBool(ofxTweakbar* pBar, string pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	bool getValue();
	void setValue(bool bValue);
};
#endif
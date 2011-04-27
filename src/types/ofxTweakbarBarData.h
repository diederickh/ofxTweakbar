#ifndef OFXTWEAKBARBARDATAH
#define OFXTWEAKBARBARDATAH

#include "ofxTweakbarType.h"
#include <string>
using namespace std;


// This type is used to store tweakbar specific data 
// like the position, is it opened/close, specific size
// etc..
class ofxTweakbarBarData : public ofxTweakbarType {
public:
	ofxTweakbarBarData(ofxTweakbar* pBar, string pName, void* pValue = NULL);
	virtual OFX_TW_TYPE getType();
	bool getValue();
	void setValue();
	int getValuesWidth();
	float getX();
	float getY();
	bool getBool();
	void setType(OFX_TW_TYPE nType);

private:
	OFX_TW_TYPE internal_type;
};
#endif
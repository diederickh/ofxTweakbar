#include "ofxTweakbarFloat.h"
ofxTweakbarFloat::ofxTweakbarFloat(
	 ofxTweakbar* pBar
	,const char* pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

TwType ofxTweakbarFloat::getType() {
	return TW_TYPE_FLOAT;
}

void ofxTweakbarFloat::setValue(float fValue) {
	float* p = static_cast<float*>(value);
	*p = fValue;
}

float ofxTweakbarFloat::getValue() {
	float p = *static_cast<float*>(value);
	return p;
}
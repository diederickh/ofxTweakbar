#include "ofxTweakbarFloat.h"
ofxTweakbarFloat::ofxTweakbarFloat(
	 ofxTweakbar* pBar
	,string pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

OFX_TW_TYPE ofxTweakbarFloat::getType() {
	return OFX_TW_TYPE_FLOAT;
}

void ofxTweakbarFloat::setValue(float fValue) {
	float* p = static_cast<float*>(value);
	*p = fValue;
}

float ofxTweakbarFloat::getValue() {
	float p = *static_cast<float*>(value);
	return p;
}
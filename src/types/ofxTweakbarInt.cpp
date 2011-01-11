#include "ofxTweakbarInt.h"

ofxTweakbarInt::ofxTweakbarInt(
	 ofxTweakbar* pBar
	,const char* pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

OFX_TW_TYPE ofxTweakbarInt::getType() {
	return OFX_TW_TYPE_INT32;
}


int ofxTweakbarInt::getValue() {
	int int_value = *static_cast<int*>(value);
	return int_value;
}

void ofxTweakbarInt::setValue(int nValue) {
	int* v = static_cast<int*>(value);
	*v = nValue;
}
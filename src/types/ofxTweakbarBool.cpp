#include "ofxTweakbarBool.h"

ofxTweakbarBool::ofxTweakbarBool(
	 ofxTweakbar* pBar
	,const char* pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

TwType ofxTweakbarBool::getType() {
	return TW_TYPE_BOOLCPP;
}

bool ofxTweakbarBool::getValue() {
	bool bool_value = *static_cast<bool*>(value);
	return bool_value;
}

void ofxTweakbarBool::setValue(bool bValue) {
	bool* b = static_cast<bool*>(value);
	*b = bValue;
}
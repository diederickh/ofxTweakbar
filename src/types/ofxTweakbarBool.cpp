#include "ofxTweakbarBool.h"

ofxTweakbarBool::ofxTweakbarBool(
	 ofxTweakbar* pBar
	,string pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

OFX_TW_TYPE ofxTweakbarBool::getType() {
	return OFX_TW_TYPE_BOOL;
}

bool ofxTweakbarBool::getValue() {
	bool bool_value = *static_cast<bool*>(value);
	return bool_value;
}

void ofxTweakbarBool::setValue(bool bValue) {
	bool* b = static_cast<bool*>(value);
	*b = bValue;
}
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

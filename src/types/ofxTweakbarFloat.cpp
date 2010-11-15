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

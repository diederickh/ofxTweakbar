#include "ofxTweakbarVec3f.h"

ofxTweakbarVec3f::ofxTweakbarVec3f(
	 ofxTweakbar* pBar
	,const char* pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

TwType ofxTweakbarVec3f::getType() {
	return TW_TYPE_DIR3F;
}


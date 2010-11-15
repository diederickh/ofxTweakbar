#include "ofxTweakbarColor3f.h"

ofxTweakbarColor3f::ofxTweakbarColor3f(
	 ofxTweakbar* pBar
	,const char* pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
//	std::cout << "NAML:" << pName << std:endl;
}

TwType ofxTweakbarColor3f::getType() {
	return TW_TYPE_COLOR3F;
}


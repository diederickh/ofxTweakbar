#include "ofxTweakbarSeparator.h"
#include "ofxTweakbarColor3f.h"

ofxTweakbarSeparator::ofxTweakbarSeparator(
	 ofxTweakbar* pBar
	,const char* pName
)
	:ofxTweakbarType(pBar, pName, NULL) 
{
}

TwType ofxTweakbarSeparator::getType() {
	return TW_TYPE_UNDEF;
}

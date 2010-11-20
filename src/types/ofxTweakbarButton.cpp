#include "ofxTweakbarButton.h"

ofxTweakbarButton::ofxTweakbarButton(
	 ofxTweakbar* pBar
	,const char* pName

)
:ofxTweakbarType(pBar, pName, NULL) 
{
}

TwType ofxTweakbarButton::getType() {
	return TW_TYPE_UNDEF; 
}
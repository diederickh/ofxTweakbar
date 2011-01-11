#include "ofxTweakbarButton.h"

ofxTweakbarButton::ofxTweakbarButton(
	 ofxTweakbar* pBar
	,const char* pName

)
:ofxTweakbarType(pBar, pName, NULL) 
{
}

OFX_TW_TYPE ofxTweakbarButton::getType() {
	return OFX_TW_TYPE_UNDEF; 
}
#include "ofxTweakbarSeparator.h"
#include "ofxTweakbarColor3f.h"

ofxTweakbarSeparator::ofxTweakbarSeparator(
	 ofxTweakbar* pBar
	,string pName
)
	:ofxTweakbarType(pBar, pName, NULL) 
{
}

OFX_TW_TYPE ofxTweakbarSeparator::getType() {
	return OFX_TW_TYPE_UNDEF;
}

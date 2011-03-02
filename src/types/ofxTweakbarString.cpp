#include "ofxTweakbarString.h"
ofxTweakbarString::ofxTweakbarString(ofxTweakbar* pBar, string sName, void *pValue)
:ofxTweakbarType(pBar, sName, pValue)
{
	TwCopyStdStringToClientFunc(ofxTweakbarStringCopy); // CopyStdStringToClient implementation is given above

}


OFX_TW_TYPE ofxTweakbarString::getType() {
	return OFX_TW_TYPE_STRING;
}

string ofxTweakbarString::getValue() {
	string val = *static_cast<string*>(value);
	return val;
}

void ofxTweakbarString::setValue(string sValue) {
	string* p = static_cast<string*>(value);
	*p = sValue;
}


#include "ofxTweakbarQuat4f.h"
#include "ofMain.h"
ofxTweakbarQuat4f::ofxTweakbarQuat4f(
	 ofxTweakbar* pBar
	,string pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{
}

OFX_TW_TYPE ofxTweakbarQuat4f::getType() {
	return OFX_TW_TYPE_QUAT4F;
}


float ofxTweakbarQuat4f::getX() {
	return *static_cast<float*>(value);
}


float ofxTweakbarQuat4f::getY() {
	float* p = static_cast<float*>(value);
	return p[1];
}

float ofxTweakbarQuat4f::getZ() {
	float* p = static_cast<float*>(value);
	return p[2];
}

float ofxTweakbarQuat4f::getS() {
	float* p = static_cast<float*>(value);
	return p[3];
}

void ofxTweakbarQuat4f::setValue(float fX, float fY, float fZ, float fS) {
	float* p = static_cast<float*>(value);
	p[0] = fX;
	p[1] = fY;
	p[2] = fZ;
	p[3] = fS;
}

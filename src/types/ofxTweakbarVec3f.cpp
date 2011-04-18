#include "ofxTweakbarVec3f.h"

ofxTweakbarVec3f::ofxTweakbarVec3f(
	 ofxTweakbar* pBar
	,string pName
	,void* pValue
)
	:ofxTweakbarType(pBar, pName, pValue) 
{	
}

OFX_TW_TYPE ofxTweakbarVec3f::getType() {
	return OFX_TW_TYPE_VEC3F;
}

float ofxTweakbarVec3f::getX() {
	return *static_cast<float*>(value);
}

float ofxTweakbarVec3f::getY() {
	void* t = value;
	float* p = static_cast<float*>(value);
	return p[1];
}

float ofxTweakbarVec3f::getZ() {
	float* p = static_cast<float*>(value);
	return p[2];

}

void ofxTweakbarVec3f::setValue(float fX, float fY, float fZ) {
	float* p = static_cast<float*>(value);
	p[0] = fX;
	p[1] = fY;
	p[2] = fZ;
}

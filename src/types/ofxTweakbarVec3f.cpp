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

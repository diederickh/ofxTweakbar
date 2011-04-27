#ifndef OFXTWEAKBARSTRINGH
#define OFXTWEAKBARSTRINGH
#include "ofxTweakbarType.h"
#include <string>
using namespace std;

inline void TW_CALL ofxTweakbarStringCopy(string& sDest, const string& sSource) {
  sDest = sSource;
}


class ofxTweakbarString : public ofxTweakbarType {
public:
	ofxTweakbarString(ofxTweakbar* pBar, string pName, void* pValue);
	virtual OFX_TW_TYPE getType();
	string getValue();
	void setValue(string nValue);
};
#endif
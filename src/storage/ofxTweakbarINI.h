#ifndef OFXTWEAKBARINIH
#define OFXTWEAKBARINIH

#include "ofxIniFile.h"
#include "ofxTweakbarStorage.h"

#include <map>

class ofxTweakbar;
class ofxTweakbarINI : public ofxTweakbarStorage{
public:
	ofxTweakbarINI(ofxTweakbar* pBar, ofxIniFile* pIni);
	virtual void store();
	virtual void retrieve();
private:
	ofxIniFile* ini;
};
#endif
#ifndef OFXTWEAKBARINIH
#define OFXTWEAKBARINIH
	
#include "ofxTweakbarStorage.h"
#include <map>

class ofxIniFile;
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
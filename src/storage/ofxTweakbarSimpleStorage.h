#ifndef OFXTWEAKBARSIMPLESTORAGEH
#define OFXTWEAKBARSIMPLESTORAGEH
#include "ofxIniFile.h"
#include "ofxTweakbarStorage.h"

#include <map>

class ofxTweakbarSimpleStorage : public ofxTweakbarStorage {
public: 
	ofxTweakbarSimpleStorage(ofxTweakbar* pBar);
	virtual void store();
	virtual void retrieve();
};
#endif
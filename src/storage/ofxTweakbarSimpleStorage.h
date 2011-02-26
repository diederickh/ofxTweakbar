#ifndef OFXTWEAKBARSIMPLESTORAGEH
#define OFXTWEAKBARSIMPLESTORAGEH

#include "ofxTweakbarStorage.h"
#include <map>
#include <string>
using namespace std;

class ofxTweakbarSimpleStorage : public ofxTweakbarStorage {
public: 
	ofxTweakbarSimpleStorage(ofxTweakbar* pBar);
	virtual void store();
	virtual void retrieve();
	string getPath();
};
#endif
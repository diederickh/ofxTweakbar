#ifndef OFXTWEAKBARTYPEH
#define OFXTWEAKBARTYPEH

#include "AntTweakBar.h"
#include <map>
class ofxTweakbar;
class ofxTweakbarType {
public:
	ofxTweakbarType(ofxTweakbar* pBar, const char* pName, void* pValue);
	virtual TwType getType() = 0;
	virtual ofxTweakbarType* setKey(std::string sKey);
	virtual ofxTweakbarType* setInc(std::string sInc);
	virtual ofxTweakbarType* setDecr(std::string sDecr);
	virtual ofxTweakbarType* setStep(std::string sStep);
	virtual ofxTweakbarType* setMin(std::string sMin);
	virtual ofxTweakbarType* setMax(std::string sMax);
	virtual ofxTweakbarType* setLabel(std::string sLabel);
	virtual ofxTweakbarType* setGroup(std::string sGroup);
	ofxTweakbar* getBar();
	const char* getName();

protected:
	const char* name;
	TwType type; 
	std::map<std::string, std::string>  properties;
	void* value;
	
private:
	ofxTweakbar* bar;
};
#endif
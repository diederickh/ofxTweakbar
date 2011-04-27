#ifndef OFXTWEAKBARTYPEH
#define OFXTWEAKBARTYPEH

#ifndef OFXTWTYPE 
#define OFXTWTYPE



enum OFX_TW_TYPE {
	OFX_TW_TYPE_BOOL
	,OFX_TW_TYPE_INT32
	,OFX_TW_TYPE_COLOR3F
	,OFX_TW_TYPE_FLOAT
	,OFX_TW_TYPE_QUAT4F
	,OFX_TW_TYPE_VEC3F
	,OFX_TW_TYPE_VEC2F
	,OFX_TW_TYPE_UNDEF
	,OFX_TW_TYPE_LIST
	,OFX_TW_TYPE_STRING
	,OFX_TW_TYPE_FILES
	
	,OFX_TW_TYPE_BAR_POSITION
	,OFX_TW_TYPE_BAR_SIZE
	,OFX_TW_TYPE_BAR_OPENED
	,OFX_TW_TYPE_BAR_VALUES_WIDTH
};
#endif

#include "ofMain.h"
#include "AntTweakBar.h"
#include <map>
class ofxTweakbar;
class ofxTweakbarType {
public:
	ofxTweakbarType(ofxTweakbar* pBar, std::string pName, void* pValue);
	virtual OFX_TW_TYPE getType() = 0;
	virtual ofxTweakbarType* setKey(std::string sKey);
	virtual ofxTweakbarType* setInc(std::string sInc);
	virtual ofxTweakbarType* setDecr(std::string sDecr);
	virtual ofxTweakbarType* setStep(std::string sStep);
	virtual ofxTweakbarType* setMin(std::string sMin);
	virtual ofxTweakbarType* setMax(std::string sMax);
	virtual ofxTweakbarType* setLabel(std::string sLabel);
	virtual ofxTweakbarType* setGroup(std::string sGroup);
	virtual ofxTweakbarType* setPrecision(std::string sPrecision);
	virtual ofxTweakbarType* setOpened(bool bOpenend);
	virtual ofxTweakbarType* open();
	virtual ofxTweakbarType* close();
	virtual bool isOpened();
	ofxTweakbar* getBar();
	const char* getName(); // TODO: should return string
	string getLabel();

protected:
	std::string name;
	OFX_TW_TYPE type; 
	std::map<std::string, std::string>  properties;
	void* value;
	ofxTweakbar* bar;
};
#endif
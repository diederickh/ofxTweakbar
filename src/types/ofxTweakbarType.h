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

	template<typename T>
	ofxTweakbarType* setKey(T t) {
		stringstream ss;
		ss << t;
		return setKey(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setInc(T t) {
		stringstream ss;
		ss << t;
		return setInc(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setDecr(T t) {
		stringstream ss;
		ss << t;
		return setDecr(ss.str());
	}
	
	
	template<typename T>
	ofxTweakbarType* setStep(T t) {
		stringstream ss;
		ss << t;
		return setStep(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setMin(T t) {
		stringstream ss;
		ss << t;
		return setMin(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setMax(T t) {
		stringstream ss;
		ss << t;
		return setMax(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setLabel(T t) {
		stringstream ss;
		ss << t;
		return setLabel(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setGroup(T t) {
		stringstream ss;
		ss << t;
		return setGroup(ss.str());
	}
	
	template<typename T>
	ofxTweakbarType* setPrecision(T t) {
		stringstream ss;
		ss << t;
		return setPrecision(ss.str());
	}
		
	template<typename T>
	ofxTweakbarType* setOpened(T t) {
		stringstream ss;
		ss << t;
		return setOpened(ss.str());
	}
	
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
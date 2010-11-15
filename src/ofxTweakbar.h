#ifndef OFXTWEAKBARH
#define OFXTWEAKBARH
#include "AntTweakBar.h"
#include <string>
#include <map>
#include "ofxTweakbarTypes.h"
class ofxTweakbar {
public:	
	ofxTweakbar(std::string sName);
	ofxTweakbarFloat* addFloat(
			 const char* pName
			,void* pValue
			,const char* pDef = "min=0 max=1 step=0.01"
	);
	ofxTweakbarBool* addBool(
			const char* pName
			,void *pValue
			,const char* pDef = ""
	);
	
	ofxTweakbarInt* addInt(
			const char* pName
			,void *pValue
			,const char* pDef = "min=0 max=10 step=1"
	);
	
	ofxTweakbarVec3f* addVec3f(
			const char* pName
			,void *pValue
	);
	
	ofxTweakbarColor3f* addColor3f(
			const char* pName
			,void *pValue
			,const char *pDef = "colormode=rgb"
	);
	
	std::map<const char*, ofxTweakbarType*> getVariables();
	std::string getName();
	
	TwBar* getBar();
private:
	std::string name;
	TwBar* bar;
	std::map<const char *, ofxTweakbarType*> variables;
};
#endif
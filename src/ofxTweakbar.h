#ifndef OFXTWEAKBARH
#define OFXTWEAKBARH
#include "AntTweakBar.h"
#include <string>
#include <map>
#include "ofxTweakbarTypes.h"

class ofxTweakbar {
public:	
	ofxTweakbar(std::string sName);
	~ofxTweakbar();
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
			,const char* pDef = ""
	);
	
	ofxTweakbarColor3f* addColor3f(
			const char* pName
			,void *pValue
			,const char *pDef = "colormode=rgb"
	);
	
	ofxTweakbar& refresh();
	
	ofxTweakbar& close();
	
	ofxTweakbar& setSize(int nWidth, int nHeight);
	
	ofxTweakbar& setColor(int nR = 0, int nG = 0, int B = 0, int nAlpha = 255);
	
	ofxTweakbar& setFontSize(int nSize = 1);
	
	
	std::map<const char*, ofxTweakbarType*> getVariables();
	std::string getName();
	
	TwBar* getBar();
	
private:
	std::string name;
	TwBar* bar;
	std::map<const char *, ofxTweakbarType*> variables;
};
#endif
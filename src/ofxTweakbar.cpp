#include "ofxTweakbar.h"
#include "ofMain.h"
ofxTweakbar::ofxTweakbar(std::string sName)
:name(sName) // TODO maybe a bit redundant
{
	bar = TwNewBar(sName.c_str());
}

TwBar* ofxTweakbar::getBar() {
	return bar;
}

ofxTweakbarFloat* ofxTweakbar::addFloat(
		const char* pName
		,void* pValue
		,const char* pDef
) 
{
	TwAddVarRW(bar, pName, TW_TYPE_FLOAT, pValue, pDef);
	ofxTweakbarFloat* type = new ofxTweakbarFloat(this, pName, pValue);
	variables[pName] = type;
	return type;
}

ofxTweakbarBool* ofxTweakbar::addBool(
		 const char* pName
		,void *pValue
		,const char* pDef
)
{
	TwAddVarRW(bar, pName, TW_TYPE_BOOLCPP, pValue, pDef);
	ofxTweakbarBool* type = new ofxTweakbarBool(this, pName, pValue);
	variables[pName] = type;
	return type;
}


ofxTweakbarInt* ofxTweakbar::addInt(
		 const char* pName
		,void *pValue
		,const char* pDef
)
{
	TwAddVarRW(bar,pName, TW_TYPE_INT32, pValue, pDef);
	ofxTweakbarInt* type = new ofxTweakbarInt(this, pName, pValue);
	variables[pName] = type;
	return type;
}


ofxTweakbarVec3f* ofxTweakbar::addVec3f(
		const char* pName
		,void *pValue
)
{
	TwAddVarRW(bar, pName, TW_TYPE_DIR3F, &pValue,"");
	ofxTweakbarVec3f* type = new ofxTweakbarVec3f(this, pName, pValue);
	variables[pName] = type;
	return type;
}


ofxTweakbarColor3f* ofxTweakbar::addColor3f(
 		 const char* pName
		,void *pValue
		,const char *pDef
)
{
	TwAddVarRW(bar, pName, TW_TYPE_COLOR3F, pValue, pDef);
	ofxTweakbarColor3f* type = new ofxTweakbarColor3f(this, pName, pValue);
	variables[pName] = type;
	return type;
}

std::map<const char*, ofxTweakbarType*> ofxTweakbar::getVariables() {
	return variables;
}

std::string ofxTweakbar::getName() {
	return name;
}
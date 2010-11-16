#include "ofxTweakbar.h"
#include <sstream>
#include "ofMain.h"
ofxTweakbar::ofxTweakbar(std::string sName, std::string sTitle)
:name(sName) // TODO maybe a bit redundant (used by storages)
,title(sTitle)
{
	bar = TwNewBar(sName.c_str());
	setLabel(sTitle);
}

ofxTweakbar::~ofxTweakbar() {
	std::map<const char *, ofxTweakbarType*>::iterator it =  variables.begin();
	while(it != variables.end()) {
		delete it->second;
		++it;
	}
}

ofxTweakbar& ofxTweakbar::setSize(int nWidth, int nHeight) {
	ostringstream oss;
	oss << getName() << " size='" << nWidth << " " << nHeight << "'";
	TwDefine(oss.str().c_str());
	return *this;
}
	
ofxTweakbar& ofxTweakbar::setColor(int nR, int nG, int nB, int nAlpha) {
	ostringstream oss;
	oss << getName() << " color='" << nR << " " << nG << " " << nB << "' alpha=" << nAlpha;
	TwDefine(oss.str().c_str());
	return *this;
}

ofxTweakbar& ofxTweakbar::setFontSize(int nSize) {
	ostringstream oss;
	oss << getName() << " fontsize=" << nSize;
	TwDefine(oss.str().c_str());
	return *this;
}

ofxTweakbar& ofxTweakbar::setLabel(std::string sLabel) {
	ostringstream oss;
	oss << getName() << " label='" << sLabel << "'";
	TwDefine(oss.str().c_str());
	return *this;
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
		,const char* pDef 
)
{
	TwAddVarRW(bar, pName, TW_TYPE_DIR3F, &pValue,pDef);
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

ofxTweakbar& ofxTweakbar::close() {
	std::string cmd = getName() +" iconified=true";
	TwDefine(cmd.c_str());
	return *this;
}

ofxTweakbar& ofxTweakbar::refresh() {
	TwRefreshBar(getBar());
	return *this;
}
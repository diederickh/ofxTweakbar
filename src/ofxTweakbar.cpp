#include "ofMain.h"
#include "ofxTweakbar.h"
#include "ofxTweakbars.h"
#include <sstream>


ofxTweakbar::ofxTweakbar(std::string sName, std::string sTitle, bool bAutoStore, ofxTweakbars* pTweakbars)
:name(sName) // TODO maybe a bit redundant (used by storages)
,title(sTitle)
,use_autostore(bAutoStore)
,tweakbars(pTweakbars)
{

	// make sure to remove non-alpha chars from the tweakbar name
	std::string clean_name;
	for(int i = 0; i < sName.size(); ++i) {
		if(isalnum(sName[i])) {
			clean_name.push_back(sName[i]);
		}
	}
	if(clean_name.size() == 0) {
		throw "Error while creating a tweakbar; use a normal name :)";
	}
	name = clean_name;
	bar = TwNewBar(name.c_str());
	setLabel(sTitle);
	
	// create a data storage for the position.
	position = new ofxTweakbarBarData(this, "bardata_position");
	position->setType(OFX_TW_TYPE_BAR_POSITION);
	variables["bardata_position"] = position;	

	// create a data storage for the size
	size = new ofxTweakbarBarData(this, "bardata_size");
	size->setType(OFX_TW_TYPE_BAR_SIZE);
	variables["bardata_size"] = size;

	// check if we are open or closed
	size = new ofxTweakbarBarData(this, "bardata_opened");
	size->setType(OFX_TW_TYPE_BAR_OPENED);
	variables["bardata_opened"] = size;
}

ofxTweakbar::~ofxTweakbar() {
	std::map<std::string, ofxTweakbarType*>::iterator it =  variables.begin();
	while(it != variables.end()) {
		delete it->second;
		++it;
	}
}

ofxTweakbar* ofxTweakbar::setSize(int nWidth, int nHeight) {
	ostringstream oss;
	oss << getName() << " size='" << nWidth << " " << nHeight << "'";
	TwDefine(oss.str().c_str());
	return this;
}
	
ofxTweakbar* ofxTweakbar::setColor(int nR, int nG, int nB, int nAlpha) {
	ostringstream oss;
	oss << getName() << " color='" << nR << " " << nG << " " << nB << "' alpha=" << nAlpha;
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setFontSize(int nSize) {
	ostringstream oss;
	oss << getName() << " fontsize=" << nSize;
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setLabel(std::string sLabel) {
	ostringstream oss;
	oss << getName() << " label='" << sLabel << "'";
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setPosition(float nX, float nY) {
	ostringstream oss;
	oss << getName() << " position='" << nX << " " << nY << "'";
	TwDefine(oss.str().c_str());
	return this;
}


// load stored state
ofxTweakbar* ofxTweakbar::load() {
	tweakbars->load(this);
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
	ofxTweakbarFloat* type = new ofxTweakbarFloat(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_FLOAT, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarBool* ofxTweakbar::addBool(
		 const char* pName
		,void *pValue
		,const char* pDef
)
{
	ofxTweakbarBool* type = new ofxTweakbarBool(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_BOOLCPP, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarInt* ofxTweakbar::addInt(
		 const char* pName
		,void *pValue
		,const char* pDef
)
{
	ofxTweakbarInt* type = new ofxTweakbarInt(this, pName, pValue);
	TwAddVarRW(bar,type->getName(), TW_TYPE_INT32, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarVec3f* ofxTweakbar::addVec3f(
		const char* pName
		,void *pValue
		,const char* pDef 
)
{

	ofxTweakbarVec3f* type = new ofxTweakbarVec3f(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_DIR3F, pValue,pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarQuat4f* ofxTweakbar::addQuat4f(
		const char* pName
		,void *pValue
		,const char *pDef
) 
{
	ofxTweakbarQuat4f* type = new ofxTweakbarQuat4f(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_QUAT4F, pValue,pDef);
	variables[type->getName()] = type;
	return type;
}


ofxTweakbarColor3f* ofxTweakbar::addColor3f(
 		 const char* pName
		,void *pValue
		,const char *pDef
)
{
	ofxTweakbarColor3f* type = new ofxTweakbarColor3f(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_COLOR3F, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarString* ofxTweakbar::addString(
	const char* pName
	,void *pValue
	,const char* pDef 
)
{
	ofxTweakbarString* type = new ofxTweakbarString(this, pName, pValue);
	variables[type->getName()] = type;
	TwAddVarRW(bar, type->getName(), TW_TYPE_STDSTRING, pValue, pDef);
	return type;
}


ofxTweakbarSeparator* ofxTweakbar::addSeparator(
		 const char*  pName
		,const char* pDef 
) 
{
	ofxTweakbarSeparator* type = new ofxTweakbarSeparator(this, pName);
	variables[type->getName()] = type;
	TwAddSeparator(bar, type->getName(), pDef);
	return type;
}

ofxTweakbarButton* ofxTweakbar::addButton(
		const char* pName
		,TwButtonCallback fCallback
		,void* pClientData 
		,const char* pDef 
)
{
	ofxTweakbarButton* type = new ofxTweakbarButton(this, pName);
	TwAddButton(bar, type->getName(), fCallback, pClientData, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarList* ofxTweakbar::addList(
		const char* pName
		,void* pValue
		,const char* pDef 
)
{
	ofxTweakbarList* type = new ofxTweakbarList(this, pName, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

std::map<std::string, ofxTweakbarType*> ofxTweakbar::getVariables() {
	return variables;
}

std::string ofxTweakbar::getName() {
	return name;
}

bool ofxTweakbar::useAutoStore() {
	return use_autostore;
}

ofxTweakbar* ofxTweakbar::open() {
	std::string cmd = getName() +" iconified=false";
	TwDefine(cmd.c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::close() {
	std::string cmd = getName() +" iconified=true";
	TwDefine(cmd.c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::refresh() {
	TwRefreshBar(getBar());
	return this;
}


void ofxTweakbar::test(const char* pName, void* pValue) {
	TwAddVarRW(bar, pName, TW_TYPE_PIXELDATA, pValue, "");
}
#include "ofxTweakbarList.h"
#include "ofxTweakbar.h"

ofxTweakbarList::ofxTweakbarList(
	ofxTweakbar* pBar
	,string pName
	,void* pValue
	,const char* pDef
)
:ofxTweakbarType(pBar, pName, pValue)
,def_string(pDef)
,enum_values(NULL)
{
}

ofxTweakbarList::~ofxTweakbarList() {
	delete[] enum_values;
}

OFX_TW_TYPE ofxTweakbarList::getType() {
	return OFX_TW_TYPE_LIST;
}

ofxTweakbarList* ofxTweakbarList::addOption(int nID, std::string sLabel) {
	TwEnumVal option;
	option.Value = nID;
	option.Label = sLabel.c_str();
	options.push_back(option);
	return this;
}

ofxTweakbarList* ofxTweakbarList::setOptionLabel(int nID, string sLabel) {
	enum_values[nID].Label = sLabel.c_str();
	return this;
}

ofxTweakbarList* ofxTweakbarList::create() {
	enum_values = new TwEnumVal[options.size()];
	for(int i = 0; i < options.size(); ++i) {
		enum_values[i] = options.at(i);
	}
	
	enum_type = TwDefineEnum(
		 getName()
		,enum_values
		,options.size()
	);
	
	TwAddVarRW(
		getBar()->getBar()
		,getName()
		,enum_type
		,value
		,def_string
	);
	return this;
}

int ofxTweakbarList::getSelectedIndex() {
	int index_val = *static_cast<int*>(value);
	return index_val;
}

ofxTweakbarList* ofxTweakbarList::setSelectedIndex(int nID) {
	int* v = static_cast<int*>(value);
	*v = nID;
	return this;
}
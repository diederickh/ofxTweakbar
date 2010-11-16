#include "ofxTweakbarType.h"
#include "ofxTweakbar.h"
#include "ofMain.h"
ofxTweakbarType::ofxTweakbarType(ofxTweakbar* pBar, const char* pName, void* pValue)
:bar(pBar)
,name(pName)
,value(pValue)
{
}

ofxTweakbar* ofxTweakbarType::getBar() {
	return bar;
}

ofxTweakbarType* ofxTweakbarType::setKey(std::string sKey) {
	TwSetParam(bar->getBar(), name, "key", TW_PARAM_CSTRING, 1, sKey.c_str());
	properties["key"] = sKey;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setInc(std::string sInc) {
	TwSetParam(bar->getBar(), name, "keyincr", TW_PARAM_CSTRING, 1, sInc.c_str());
	properties["keyincr"] = sInc;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setDecr(std::string sDecr) {
	TwSetParam(bar->getBar(), name, "keydecr", TW_PARAM_CSTRING, 1, sDecr.c_str());
	properties["keydecr"] = sDecr;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setStep(std::string sStep) {
	TwSetParam(bar->getBar(), name, "step", TW_PARAM_CSTRING, 1, sStep.c_str());
	properties["step"] = sStep;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setMin(std::string sMin) {
	TwSetParam(bar->getBar(), name, "min", TW_PARAM_CSTRING, 1, sMin.c_str());
	properties["min"] = sMin;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setMax(std::string sMax) {
	TwSetParam(bar->getBar(), name, "max", TW_PARAM_CSTRING, 1, sMax.c_str());
	properties["max"] = sMax;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setLabel(std::string sLabel) {
	TwSetParam(bar->getBar(), name, "label", TW_PARAM_CSTRING, 1, sLabel.c_str());
	properties["label"] = sLabel;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setGroup(std::string sGroup) {	
	TwSetParam(bar->getBar(), name, "group", TW_PARAM_CSTRING, 1, sGroup.c_str());
	properties["group"] = sGroup;
	return this;
}

const char* ofxTweakbarType::getName() {
	return name;
}

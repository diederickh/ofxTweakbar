#include "ofMain.h"
#include "ofxTweakbarType.h"
#include "ofxTweakbar.h"
#include "Poco/String.h"
//#include "Poco/RegularExpression.h"

using Poco::toUpper;
using Poco::toLower;
using Poco::toLowerInPlace;
using Poco::trimInPlace;
//using Poco::RegularExpression;

ofxTweakbarType::ofxTweakbarType(ofxTweakbar* pBar, string pName, void* pValue)
:bar(pBar)
,name(pName)
,value(pValue)
{
	trimInPlace(name);
	toLowerInPlace(name);
	string clean_name;
	for(int i = 0; i < name.size(); ++i) {
		if(isalnum(name[i])) {
			clean_name.push_back(name[i]);
		}
		else {
			clean_name.push_back('_');
		}
	}
	name = clean_name;
}

ofxTweakbar* ofxTweakbarType::getBar() {
	return bar;
}

ofxTweakbarType* ofxTweakbarType::setKey(std::string sKey) {
	TwSetParam(bar->getBar(), name.c_str(), "key", TW_PARAM_CSTRING, 1, sKey.c_str());
	properties["key"] = sKey;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setInc(std::string sInc) {
	TwSetParam(bar->getBar(), name.c_str(), "keyincr", TW_PARAM_CSTRING, 1, sInc.c_str());
	properties["keyincr"] = sInc;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setDecr(std::string sDecr) {
	TwSetParam(bar->getBar(), name.c_str(), "keydecr", TW_PARAM_CSTRING, 1, sDecr.c_str());
	properties["keydecr"] = sDecr;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setStep(std::string sStep) {
	TwSetParam(bar->getBar(), name.c_str(), "step", TW_PARAM_CSTRING, 1, sStep.c_str());
	properties["step"] = sStep;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setPrecision(std::string sPrecision) {
	TwSetParam(bar->getBar(), name.c_str(), "precision", TW_PARAM_CSTRING, 1, sPrecision.c_str());
	properties["precision"] = sPrecision;
	return this;

}

ofxTweakbarType* ofxTweakbarType::setMin(std::string sMin) {
	TwSetParam(bar->getBar(), name.c_str(), "min", TW_PARAM_CSTRING, 1, sMin.c_str());
	properties["min"] = sMin;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setMax(std::string sMax) {
	TwSetParam(bar->getBar(), name.c_str(), "max", TW_PARAM_CSTRING, 1, sMax.c_str());
	properties["max"] = sMax;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setLabel(std::string sLabel) {
	TwSetParam(bar->getBar(), name.c_str(), "label", TW_PARAM_CSTRING, 1, sLabel.c_str());
	properties["label"] = sLabel;
	return this;
}

ofxTweakbarType* ofxTweakbarType::setGroup(std::string sGroup) {	
	TwSetParam(bar->getBar(), name.c_str(), "group", TW_PARAM_CSTRING, 1, sGroup.c_str());
	properties["group"] = sGroup;
	return this;
}

ofxTweakbarType* ofxTweakbarType::open() {
	return setOpened(true);
}

ofxTweakbarType* ofxTweakbarType::close() {
	return setOpened(false);
}

ofxTweakbarType* ofxTweakbarType::setOpened(bool bOpened) {
	int opened = (bOpened) ? 1 : 0;
	TwSetParam(bar->getBar(), name.c_str(), "opened", TW_PARAM_INT32, 1, &opened);
	properties["opened"] = (bOpened) ? "y" : "n";
	return this;
}

bool ofxTweakbarType::isOpened() {
	int opened; 
	TwGetParam(bar->getBar(), name.c_str(), "opened", TW_PARAM_INT32, 1, &opened);
	return opened == 1;
}

const char* ofxTweakbarType::getName() {
	return name.c_str();
}

string ofxTweakbarType::getLabel() {
	return properties["label"];
}


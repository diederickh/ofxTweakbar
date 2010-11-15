#include "ofxTweakbarINI.h"
#include "ofxTweakbar.h"
#include "ofxTweakbarTypes.h"

#include "ofMain.h"
ofxTweakbarINI::ofxTweakbarINI(ofxTweakbar* pBar, ofxIniFile* pIni)
	:ofxTweakbarStorage(pBar)
	,ini(pIni)
{
}

void ofxTweakbarINI::store() {
	std::map<const char*, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<const char*, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	TwType tw_type;
	std::string section = getBar()->getName();

	while(it != vars.end()) {
		type = it->second;
		tw_type = type->getType();
		if(tw_type == TW_TYPE_INT32) {
			ofxTweakbarInt* type_int = static_cast<ofxTweakbarInt*>(it->second);
			ini->setInt(section, type->getName(), type_int->getValue());
		}
		++it;
	}
	ini->save();
}

void ofxTweakbarINI::retrieve() {
}
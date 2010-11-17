#include "ofxTweakbarINI.h"
#include "ofxTweakbar.h"
#include "ofxTweakbarTypes.h"

ofxTweakbarINI::ofxTweakbarINI(ofxTweakbar* pBar, ofxIniFile* pIni)
	:ofxTweakbarStorage(pBar)
	,ini(pIni)
{
}

void ofxTweakbarINI::store() {
	std::map<std::string, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<std::string, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	TwType tw_type;
	std::string section = getBar()->getName();

	while(it != vars.end()) {
		type = it->second;
		tw_type = type->getType();
		if(tw_type == TW_TYPE_INT32) {
			ofxTweakbarInt* type_impl = static_cast<ofxTweakbarInt*>(it->second);
			ini->setInt(section, type->getName(), type_impl->getValue());
		}
		else if (tw_type == TW_TYPE_FLOAT) {
			ofxTweakbarFloat* type_impl = static_cast<ofxTweakbarFloat*>(it->second);
			ini->setFloat(section, type->getName(), type_impl->getValue());
		}
		else if (tw_type == TW_TYPE_BOOLCPP) {
			ofxTweakbarBool* type_impl = static_cast<ofxTweakbarBool*>(it->second);
			ini->setBool(section, type->getName(), type_impl->getValue());
		}
		else if (tw_type == TW_TYPE_COLOR3F) {
			ofxTweakbarColor3f* type_impl = static_cast<ofxTweakbarColor3f*>(it->second);
			IniVec3f v(type_impl->getX(), type_impl->getY(), type_impl->getZ());
			ini->setVec3f(section, type->getName(), v);
		}
		else if (tw_type == TW_TYPE_DIR3F) {
			ofxTweakbarVec3f* type_impl = static_cast<ofxTweakbarVec3f*>(it->second);
			IniVec3f v(type_impl->getX(), type_impl->getY(), type_impl->getZ());
			ini->setVec3f(section, type->getName(), v);
		}
		++it;
	}
	ini->save();
}

void ofxTweakbarINI::retrieve() {
	std::map<std::string, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<std::string, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	TwType tw_type;
	std::string section = getBar()->getName();

	while(it != vars.end()) {
		type = it->second;
		tw_type = type->getType();
		if(tw_type == TW_TYPE_INT32) {
			ofxTweakbarInt* type_impl = static_cast<ofxTweakbarInt*>(it->second);
			int i = ini->getInt(section, type->getName(), 0);
			type_impl->setValue(i);
		}
		else if (tw_type == TW_TYPE_FLOAT) {
			ofxTweakbarFloat* type_impl = static_cast<ofxTweakbarFloat*>(it->second);
			float f = ini->getFloat(section, type->getName(), false);
			type_impl->setValue(f);
		}
		else if (tw_type == TW_TYPE_BOOLCPP) {
			ofxTweakbarBool* type_impl = static_cast<ofxTweakbarBool*>(it->second);
			bool b = ini->getBool(section, type->getName(), false);
			type_impl->setValue(b);
		}
		else if (tw_type == TW_TYPE_COLOR3F) {
			ofxTweakbarColor3f* type_impl = static_cast<ofxTweakbarColor3f*>(it->second);
			IniVec3f v(0,0,0);
			v = ini->getVec3f(section, type->getName(), "0,0,0");
			type_impl->setValue(v.x, v.y, v.z);
		}
		else if (tw_type == TW_TYPE_DIR3F) {
			ofxTweakbarVec3f* type_impl = static_cast<ofxTweakbarVec3f*>(it->second);
			IniVec3f v(0,0,0);
			v = ini->getVec3f(section, type->getName(), "0,0,0");
			type_impl->setValue(v.x, v.y, v.z);
		}
		++it;
	}
	getBar()->refresh();
}
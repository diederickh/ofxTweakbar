#include "ofxTweakbarBarData.h"
#include "ofxTweakbar.h"
#include <iostream>
// TODO: We don't need all these internal types; we can store this as one line 

ofxTweakbarBarData::ofxTweakbarBarData(
								   ofxTweakbar* pBar
								   ,string pName
								   ,void* pValue
								   )
:ofxTweakbarType(pBar, pName, pValue) 
{	
	internal_type = OFX_TW_TYPE_UNDEF;
}

OFX_TW_TYPE ofxTweakbarBarData::getType() {
	return internal_type;
}

void ofxTweakbarBarData::setType(OFX_TW_TYPE nType) {
	internal_type = nType;
}

int ofxTweakbarBarData::getValuesWidth() {
	int val_width;
	TwGetParam(bar->getBar(), NULL, "valueswidth", TW_PARAM_INT32,1, &val_width);
	return val_width;
}

bool ofxTweakbarBarData::getBool() {
	//ofLog(OF_LOG_VERBOSE, "Saved to file: '%s'", sFileName.c_str());
	bool bool_value = false;
	int val;
	if(internal_type == OFX_TW_TYPE_BAR_OPENED) {
		TwGetParam(bar->getBar(), NULL, "iconified", TW_PARAM_INT32 , 1, &val);
	}	
	if(val == 0)
		bool_value = true;
	return bool_value;
}
	
float ofxTweakbarBarData::getX() {
	int pos[2];
	if(internal_type == OFX_TW_TYPE_BAR_POSITION) {
		TwGetParam(bar->getBar(), NULL, "position", TW_PARAM_INT32, 2, pos);
	}
	else if(internal_type == OFX_TW_TYPE_BAR_SIZE) {
		TwGetParam(bar->getBar(), NULL, "size", TW_PARAM_INT32, 2, pos);
	}
	return pos[0];
}

float ofxTweakbarBarData::getY() {
	int pos[2];
	if(internal_type == OFX_TW_TYPE_BAR_POSITION) {
		TwGetParam(bar->getBar(), NULL, "position", TW_PARAM_INT32, 2, pos);
	}
	else if(internal_type == OFX_TW_TYPE_BAR_SIZE) {
		TwGetParam(bar->getBar(), NULL, "size", TW_PARAM_INT32, 2, pos);
	}
		
	return pos[1];
}



#include "ofxTweakbarSimpleStorage.h"
#include "ofxTweakbarTypes.h"
#include "ofxTweakbar.h"
#include "ofMain.h"
#include <sstream>
#include <fstream>

ofxTweakbarSimpleStorage::ofxTweakbarSimpleStorage(ofxTweakbar* pBar)
:ofxTweakbarStorage(pBar)
{
}

void ofxTweakbarSimpleStorage::store() {
	std::map<std::string, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<std::string, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	TwType tw_type;

	// get file
	std::string section = getBar()->getName();
	std::ofstream ofs;
	std::string file = ofToDataPath(getBar()->getName() +".dat");
	ofs.open(file.c_str());
	if (ofs.fail()) {
		std::cout << "Error: could not open: " << file << std::endl;
		return;
	}
	
	// Store all values.
	while(it != vars.end()) {
		type = it->second;
		tw_type = type->getType();
		if(tw_type == TW_TYPE_INT32) {
			ofxTweakbarInt* type_impl = static_cast<ofxTweakbarInt*>(it->second);
			ofs << type_impl->getName() << "\t" << type_impl->getValue() << std::endl;
		}
		else if (tw_type == TW_TYPE_FLOAT) {
			ofxTweakbarFloat* type_impl = static_cast<ofxTweakbarFloat*>(it->second);
			ofs << type_impl->getName() << "\t" << type_impl->getValue() << std::endl;
			
		}
		else if (tw_type == TW_TYPE_BOOLCPP) {
			ofxTweakbarBool* type_impl = static_cast<ofxTweakbarBool*>(it->second);
			ofs << type_impl->getName() << "\t" << type_impl->getValue() << std::endl;	
		}
		else if (tw_type == TW_TYPE_COLOR3F) {
			ofxTweakbarColor3f* type_impl = static_cast<ofxTweakbarColor3f*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getX()	<< "\t" 
				<< type_impl->getY()	<< "\t" 
				<< type_impl->getZ()	<< std::endl;		
		}
		else if (tw_type == TW_TYPE_DIR3F) {
			ofxTweakbarVec3f* type_impl = static_cast<ofxTweakbarVec3f*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getX()	<< "\t" 
				<< type_impl->getY()	<< "\t" 
				<< type_impl->getZ()	<< std::endl;		
		}
		++it;
	}
	ofs.close();

}

void ofxTweakbarSimpleStorage::retrieve() {
	std::map<std::string, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<std::string, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	TwType tw_type;

	// create data file.
	std::ifstream ifs;
	std::string file = ofToDataPath(getBar()->getName() +".dat");
	ifs.open(file.c_str());
	if(ifs.fail()) {
		std::cout << "Error: could not open " << file << std::endl;
	}
	
	// retrieve all values.
	std::string line;
	while(getline(ifs, line)) {
		istringstream iss(line);
		std::string varname;
		iss >> varname;
		it = vars.find(varname);
		if (it != vars.end()) {
			type = it->second;
			tw_type = type->getType();
			if(tw_type == TW_TYPE_INT32) {	
				ofxTweakbarInt* type_impl = static_cast<ofxTweakbarInt*>(type);
				int int_value = 0;
				iss >> int_value;
				type_impl->setValue(int_value);
			}
			else if(tw_type == TW_TYPE_FLOAT) {
				float float_value = 0;
				iss >> float_value;
				ofxTweakbarFloat* type_impl = static_cast<ofxTweakbarFloat*>(type);
				type_impl->setValue(float_value);
			}
			else if(tw_type == TW_TYPE_BOOLCPP) {
				bool bool_value = false;
				iss >> bool_value; 
				ofxTweakbarBool* type_impl = static_cast<ofxTweakbarBool*>(type);
				type_impl->setValue(bool_value);
			}
			else if(tw_type == TW_TYPE_COLOR3F) {
				float x = 0;
				float y = 0; 
				float z = 0;
				iss >> x >> y >> z;
				ofxTweakbarColor3f* type_impl = static_cast<ofxTweakbarColor3f*>(type);
				type_impl->setValue(x,y,z);
			}
			else if(tw_type == TW_TYPE_DIR3F) {
				float x = 0;
				float y = 0; 
				float z = 0;
				iss >> x >> y >> z;
				ofxTweakbarVec3f* type_impl = static_cast<ofxTweakbarVec3f*>(type);
				type_impl->setValue(x,y,z);
			}
		}
		else {
		}
	}
	getBar()->refresh();
}

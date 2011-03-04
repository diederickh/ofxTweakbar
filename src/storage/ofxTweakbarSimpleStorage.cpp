#include "ofxTweakbarSimpleStorage.h"
#include "ofxTweakbarTypes.h"
#include "ofxTweakbar.h"
#include "ofMain.h"
#include <sstream>
#include <fstream>
#include "Poco/Path.h"
#include "Poco/Platform.h"

ofxTweakbarSimpleStorage::ofxTweakbarSimpleStorage(ofxTweakbar* pBar)
:ofxTweakbarStorage(pBar)
{
}

string ofxTweakbarSimpleStorage::getPath() {
	// When using the testApp::testApp() constructor the current working
	// directory is different than when in the testApp::setup(). Kind of wierd,
	// but this function takes this into account.
	
	// TODO: test/update when 007 stable is released
	string filepath;
	Poco::Path p;
	string curr_path = p.current();
	Poco::Path p_data(curr_path + "data/");
	Poco::File file(p_data);
	if(file.exists()) {
		filepath = curr_path +"data/" +getBar()->getFileName();
	}
	else {
		if(POCO_OS_MAC_OS_X) {
			filepath = "../../../data/" +getBar()->getFileName();
		} 
		else {	
			filepath = "data/" +getBar()->getFileName();
		}
	}
	return filepath;
}

void ofxTweakbarSimpleStorage::store() {
	std::map<std::string, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<std::string, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	OFX_TW_TYPE tw_type;

	// get file
	std::string section = getBar()->getName();
	std::ofstream ofs;
	std::string file = getPath(); 
	ofs.open(file.c_str());
	if (ofs.fail()) {
		std::cout << "Error: could not open: " << file << std::endl;
		return;
	}
	
	// Store all values.
	while(it != vars.end()) {
		type = it->second;
		tw_type = type->getType();
		if(tw_type == OFX_TW_TYPE_INT32) {
			ofxTweakbarInt* type_impl = static_cast<ofxTweakbarInt*>(it->second);
			ofs << type_impl->getName() << "\t" << type_impl->getValue() << std::endl;
		}
		else if (tw_type == OFX_TW_TYPE_FLOAT) {
			ofxTweakbarFloat* type_impl = static_cast<ofxTweakbarFloat*>(it->second);
			ofs << type_impl->getName() << "\t" << type_impl->getValue() << std::endl;
			
		}
		else if (tw_type == OFX_TW_TYPE_BOOL) {
			ofxTweakbarBool* type_impl = static_cast<ofxTweakbarBool*>(it->second);
			ofs << type_impl->getName() << "\t" << type_impl->getValue() << std::endl;	
		}
		else if (tw_type == OFX_TW_TYPE_COLOR3F) {
			ofxTweakbarColor3f* type_impl = static_cast<ofxTweakbarColor3f*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getX()	<< "\t" 
				<< type_impl->getY()	<< "\t" 
				<< type_impl->getZ()	<< std::endl;		
		}
		else if (tw_type == OFX_TW_TYPE_QUAT4F) {
			ofxTweakbarQuat4f* type_impl = static_cast<ofxTweakbarQuat4f*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getX()	<< "\t" 
				<< type_impl->getY()	<< "\t" 
				<< type_impl->getZ()	<< "\t"
				<< type_impl->getS()	<< std::endl;		
		}
		else if (tw_type == OFX_TW_TYPE_VEC3F) {
			ofxTweakbarVec3f* type_impl = static_cast<ofxTweakbarVec3f*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getX()	<< "\t" 
				<< type_impl->getY()	<< "\t" 
				<< type_impl->getZ()	<< std::endl;		
		}
		else if (tw_type == OFX_TW_TYPE_BAR_POSITION) {
			ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
			ofs << type_impl->getName()	<< "\t"
				<< type_impl->getX()	<< "\t"
				<< type_impl->getY()	<< std::endl;
		}
		else if (tw_type == OFX_TW_TYPE_BAR_SIZE) {
			ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
			ofs << type_impl->getName()	<< "\t"
				<< type_impl->getX()	<< "\t"
				<< type_impl->getY()	<< std::endl;
		}
		else if (tw_type == OFX_TW_TYPE_BAR_OPENED) {
			ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
			ofs << type_impl->getName()	<< "\t"
				<< type_impl->getBool() << std::endl;
		}
		else if (tw_type == OFX_TW_TYPE_BAR_VALUES_WIDTH) {
			ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
			ofs << type_impl->getName()	<< "\t"
				<< type_impl->getValuesWidth() << std::endl;
		}
		else if(tw_type == OFX_TW_TYPE_LIST) {
			ofxTweakbarList* type_impl = static_cast<ofxTweakbarList*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getSelectedIndex() << std::endl;
		}
		else if(tw_type == OFX_TW_TYPE_STRING) {
			ofxTweakbarString* type_impl = static_cast<ofxTweakbarString*>(it->second);
			ofs << type_impl->getName() << "\t"
				<< type_impl->getValue() << std::endl;
		}
		++it;
	}
	ofs.close();

}

void ofxTweakbarSimpleStorage::retrieve() {
	std::map<std::string, ofxTweakbarType*> vars = getBar()->getVariables();
	std::map<std::string, ofxTweakbarType*>::iterator it = vars.begin();
	ofxTweakbarType* type = NULL;
	OFX_TW_TYPE tw_type;
	
	// create data file.
	std::ifstream ifs;
	std::string file = getPath();
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
			if(tw_type == OFX_TW_TYPE_INT32) {	
				ofxTweakbarInt* type_impl = static_cast<ofxTweakbarInt*>(type);
				int int_value = 0;
				iss >> int_value;
				type_impl->setValue(int_value);
			}
			else if(tw_type == OFX_TW_TYPE_FLOAT) {
				float float_value = 0;
				iss >> float_value;
				ofxTweakbarFloat* type_impl = static_cast<ofxTweakbarFloat*>(type);
				type_impl->setValue(float_value);
			}
			else if(tw_type == OFX_TW_TYPE_BOOL) {
				bool bool_value = false;
				iss >> bool_value; 
				ofxTweakbarBool* type_impl = static_cast<ofxTweakbarBool*>(type);
				type_impl->setValue(bool_value);
			}
			else if(tw_type == OFX_TW_TYPE_COLOR3F) {
				float x = 0;
				float y = 0; 
				float z = 0;
				iss >> x >> y >> z;
				ofxTweakbarColor3f* type_impl = static_cast<ofxTweakbarColor3f*>(type);
				type_impl->setValue(x,y,z);
			}
			else if(tw_type == OFX_TW_TYPE_QUAT4F) {
				float x = 0;
				float y = 0; 
				float z = 0;
				float s = 0;
				iss >> x >> y >> z >> s;
				ofxTweakbarQuat4f* type_impl = static_cast<ofxTweakbarQuat4f*>(type);
				type_impl->setValue(x,y,z,s);
			}
			else if(tw_type == OFX_TW_TYPE_VEC3F) {
				float x = 0;
				float y = 0; 
				float z = 0;
				iss >> x >> y >> z;
				ofxTweakbarVec3f* type_impl = static_cast<ofxTweakbarVec3f*>(type);
				type_impl->setValue(x,y,z);
			}
			else if (tw_type == OFX_TW_TYPE_BAR_POSITION) {
				float x = 0;
				float y = 0;
				ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
				iss >> x >> y;
				getBar()->setPosition(x,y);
			}
			else if (tw_type == OFX_TW_TYPE_BAR_SIZE) {
				float x = 0;
				float y = 0;
				ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
				iss >> x >> y;
				getBar()->setSize(x,y);
			}
			else if (tw_type == OFX_TW_TYPE_BAR_OPENED) {
				bool is_opened;
				ofxTweakbarBarData* type_impl = static_cast<ofxTweakbarBarData*>(it->second);
				iss >> is_opened;
				if(is_opened) {
					getBar()->open();
				}
				else { 
					getBar()->close();
				}
			}
			else if (tw_type == OFX_TW_TYPE_BAR_VALUES_WIDTH) {
				int val_width = 0;
				iss >> val_width;
				getBar()->setValuesWidth(val_width);
			}
			else if(tw_type == OFX_TW_TYPE_LIST) {
				ofxTweakbarList* type_impl = static_cast<ofxTweakbarList*>(it->second);
				int selected_index = 0;
				iss >> selected_index;
				type_impl->setSelectedIndex(selected_index);
			}
			else if(tw_type == OFX_TW_TYPE_STRING) {
				ofxTweakbarString* type_impl = static_cast<ofxTweakbarString*>(it->second);
				string value;
				iss >> value;
				type_impl->setValue(value);
			}

		}
		else {
		}
	}
	getBar()->refresh();
}

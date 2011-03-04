#ifndef OFXTWEAKBARFILESH
#define OFXTWEAKBARFILESH
#include "ofMain.h"
#include "ofxTweakbarType.h"
#include "ofxTweakbarList.h"
#include <map>

#include "Poco/Glob.h"
#include "Poco/Path.h"

using Poco::Path;
using Poco::Glob;
using namespace std;

/*
inline void TW_CALL ofxTweakbarStringCopy(string& sDest, const string& sSource) {
  sDest = sSource;
}
*/

class ofxTweakbarFiles : public ofxTweakbarType {
public:
	ofxTweakbarFiles(ofxTweakbar* pBar, string pName, void* pValue, const char* pDef = NULL);
	virtual OFX_TW_TYPE getType();
	ofxTweakbarFiles* setPath(string sPath, string sExt = "*.*");
	ofxTweakbarFiles* create();
	string getSelectedFilePath();
	string getSelectedFileName();
	void reload();
	virtual ofxTweakbarFiles* setLabel(std::string sLabel);
	int selected_file;
private:
	bool loaded;
	string path;
	string ext;
	std::map<int, Poco::Path> files;
	ofxTweakbarList* list;

	//string getValue();
	
	//void setValue(string nValue);
};
#endif
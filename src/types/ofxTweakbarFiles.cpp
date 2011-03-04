#include "ofxTweakbarFiles.h"
#include "Poco/Glob.h"
#include "Poco/Path.h"
#include "ofxTweakbar.h"

using Poco::Path;
using Poco::Glob;
ofxTweakbarFiles::ofxTweakbarFiles(ofxTweakbar* pBar, string pName, void* pValue, const char* pDef) 
:ofxTweakbarType(pBar, pName, pValue)
,selected_file(0)
,loaded(false)
{

}

OFX_TW_TYPE ofxTweakbarFiles::getType() {
	return OFX_TW_TYPE_FILES;
}

ofxTweakbarFiles* ofxTweakbarFiles::setPath(string sPath, string sExt) {
	path = sPath;
	ext = sExt;
	return this;
}

ofxTweakbarFiles* ofxTweakbarFiles::create() {
	// creat the list.
	list = getBar()->addList(getName(),&selected_file);
	reload();
	list->create();
	getBar()->variables[getName()] = this; // we must overule this! else we "are" a listbox.
	return this;
}

void ofxTweakbarFiles::reload() {
	Path p(path);
	p.append(ext);
	
	// find files and add them to the listbox.
	set<string> found_files;
	Glob::glob(p.toString(), found_files);

	std::set<std::string>::iterator it = found_files.begin();
	int i = 0;
	for (; it != found_files.end(); ++it) {
		Path file_p(*it);
		cout << file_p.getFileName() << endl;
		files.insert(std::pair<int, Path>(i, file_p));
		if(!loaded) {
			list->addOption(i, file_p.getFileName());
		}
		else {
			// TODO: make this work :-)
			//list->setLabel(i, file_p.getFileName() +"update");
		}
		++i;
	}
	loaded = true;
}

string ofxTweakbarFiles::getSelectedFilePath() {
	Poco::Path selected_path = files[selected_file];
	return selected_path.toString();
}

string ofxTweakbarFiles::getSelectedFileName() {
	Poco::Path selected_path = files[selected_file];
	return selected_path.getFileName();
}

ofxTweakbarFiles* ofxTweakbarFiles::setLabel(std::string sLabel) {
	ofxTweakbarType::setLabel(sLabel);
	return this;
}

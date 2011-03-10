#ifndef OFXTWEAKBARLISTH
#define OFXTWEAKBARLISTH

#include "ofxTweakbarType.h"
#include <vector>
#include <string>
using namespace std;

/* Adds a dropdown listbox:

bar->addList("animal_list",&index_list)
		->addOption(0,"Monkey")
		->addOption(1,"Bird")
		->addOption(2,"Horse")
		->addOption(3,"Cat")
		->addOption(4,"Dog")
		->addOption(5,"Donkey")
		->addOption(6,"Mouse")
		->addOption(7,"Duck")
		->addOption(8,"Pig")
		->create();
	
*/

class ofxTweakbarList : public ofxTweakbarType {
public:
	ofxTweakbarList(
		ofxTweakbar* pBar
		,string pName
		,void* pValue
		,const char* pDef = NULL
	);
	~ofxTweakbarList();
	
	virtual OFX_TW_TYPE getType();
	ofxTweakbarList* addOption(int nID, string sLabel);
	ofxTweakbarList* setOptionLabel(int nID, string sLabel);
	
	ofxTweakbarList* create(); // call this when you added all labels.
	int getSelectedIndex();
	ofxTweakbarList* setSelectedIndex(int nID);
	
	std::vector<TwEnumVal> options;
	TwType enum_type;
	TwEnumVal* enum_values;
	const char* def_string;
};
#endif
#ifndef OFXTWEAKBARH
#define OFXTWEAKBARH
#include "AntTweakBar.h"
#include <string>
#include <map>
#include "ofxTweakbarTypes.h"
#include "ofxTweakbarListener.h"

class ofxTweakbars;

class ofxTweakbar {
public:	
	ofxTweakbar(std::string sName, std::string sTitle, bool bUseAutoStore, ofxTweakbars* pTweakbars);
	~ofxTweakbar();
	
	ofxTweakbarFloat* addFloat(
			 const char* pName
			,void* pValue
			,const char* pDef = "min=0 max=1 step=0.01"
	);
	ofxTweakbarBool* addBool(
			const char* pName
			,void *pValue
			,const char* pDef = ""
	);
	
	ofxTweakbarInt* addInt(
			const char* pName
			,void *pValue
			,const char* pDef = "min=0 max=10 step=1"
	);
	
	ofxTweakbarVec3f* addVec3f(
			const char* pName
			,void *pValue
			,const char* pDef = ""
	);
	
	ofxTweakbarColor3f* addColor3f(
			const char* pName
			,void *pValue
			,const char *pDef = "colormode=rgb"
	);
	
	ofxTweakbarQuat4f* addQuat4f(
			const char* pName
			,void *pValue
			,const char *pDef = ""
	);
	
	ofxTweakbarSeparator* addSeparator(
			 const char* pName = ""
			,const char* pDef = ""
	);	
	
	// -- testing custom types -- 
	void test(const char* pName , void* pValue);
	/**
	    example of adding a callback, where we have "ofxTweakbar* bar"
		=============================================================
		
		void TW_CALL callback(void* client) {
			printf("callback");
		}
		
		void testApp::setup() {
			bar->addButton("somename", callback,this);
		}
	*/

	ofxTweakbarButton* addButton(
			const char* pName
			,TwButtonCallback fCallback
			,void* pClientData = NULL
			,const char* pDef = ""
	);
	
	ofxTweakbarList* addList(
			const char* pName
			,void* pValue
			,const char* pDef = ""
	);
	
	ofxTweakbar* refresh();
	
	ofxTweakbar* close();
	
	ofxTweakbar* open();
	
	ofxTweakbar* setSize(int nWidth, int nHeight);
	
	ofxTweakbar* setColor(int nR = 0, int nG = 0, int B = 0, int nAlpha = 255);
	
	ofxTweakbar* setFontSize(int nSize = 1);

	ofxTweakbar* setLabel(std::string sLabel);
	
	ofxTweakbar* setPosition(float nX, float nY);

	ofxTweakbar* load(); 
	
	ofxTweakbar* store();
	
	std::map<std::string, ofxTweakbarType*> getVariables();
	std::string getName();
	TwBar* getBar();
	bool useAutoStore();
	
	void changed();
	void addListener(ofxTweakbarListener* pListener);

private:
	int testval;
	ofxTweakbarBarData* position;
	ofxTweakbarBarData* size;
	ofxTweakbarBarData* is_open;
	
	ofxTweakbars* tweakbars;
	bool use_autostore;
	std::string title;
	std::string name;
	TwBar* bar;
	std::map<std::string, ofxTweakbarType*> variables;
	
	ofxTweakbarListener * listener;
};
#endif
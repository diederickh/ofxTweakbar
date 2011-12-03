#ifndef OFXTWEAKBARSH
#define OFXTWEAKBARSH
#include <map>
#include "ofMain.h"
#include "ofxTweakbarSimpleStorage.h"

class ofxTweakbar;
class ofxTweakbars {
public:
	static ofxTweakbar* create(std::string sName, std::string sTitle, bool bUseAutoStore = true);
	static void draw();
	static void toggle();
	static void hide();
	static void show();
	static ofxTweakbars* getInstance();
	static void save(ofxTweakbar* pBar, string sFileName = "");
	static void load(ofxTweakbar* pBar, string sFileName = "");
	void setEventHandlers();
	void unsetEventHandlers();
	void init();
	bool isInitialized();
	static bool isVisible();
	void addTweakbarToList(string sName, ofxTweakbar* pBar); //only for global instance
private:
	ofxTweakbars();
	~ofxTweakbars(); 

	void autoStore();
	

	std::map<std::string, ofxTweakbar*> bars;
	
	bool visible;		
	bool is_initialized;
	ofxTweakbarSimpleStorage simple_storage;
	
	// EVENT HANDLERS
	// -------------------------------------------------------------------------
	void keyPressed(ofKeyEventArgs& rArgs);
	void mouseMoved(ofMouseEventArgs& rArgs);
	void mousePressed(ofMouseEventArgs& rArgs);
	void mouseReleased(ofMouseEventArgs& rArgs);
	void mouseDragged(ofMouseEventArgs& rArgs);
	void windowResized(ofResizeEventArgs& rArgs);

	static ofxTweakbars instance;

};

#endif
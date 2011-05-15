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
	void load(ofxTweakbar* pBar);
	void store(ofxTweakbar* pBar);
private:
	ofxTweakbars();
	~ofxTweakbars(); 
	void init();
	void autoStore();
	void changed();
	
	std::map<std::string, ofxTweakbar*> bars;
	bool visible;
	bool is_initialized;
	ofxTweakbarSimpleStorage simple_storage;
	
	// EVENT HANDLERS
	// -------------------------------------------------------------------------
	void setEventHandlers();
	void unsetEventHandlers();
	void keyPressed(ofKeyEventArgs& rArgs);
	void mouseMoved(ofMouseEventArgs& rArgs);
	void mousePressed(ofMouseEventArgs& rArgs);
	void mouseReleased(ofMouseEventArgs& rArgs);
	void mouseDragged(ofMouseEventArgs& rArgs);
	void windowResized(ofResizeEventArgs& rArgs);

	static ofxTweakbars instance;

};

#endif
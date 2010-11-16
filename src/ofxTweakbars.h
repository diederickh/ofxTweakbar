#ifndef OFXTWEAKBARSH
#define OFXTWEAKBARSH
#include <map>
#include "ofMain.h"

class ofxTweakbar;
class ofxTweakbars {
public:
	ofxTweakbars();
	~ofxTweakbars();
	ofxTweakbar* addTweakbar(std::string sName, std::string sTitle);
	void draw();
	void toggle();
private:
	std::map<std::string, ofxTweakbar*> bars;
	bool visible;
	
	// EVENT HANDLERS
	// -------------------------------------------------------------------------
	void setEventHandlers();
	void keyPressed(ofKeyEventArgs& rArgs);
	void mouseMoved(ofMouseEventArgs& rArgs);
	void mousePressed(ofMouseEventArgs& rArgs);
	void mouseReleased(ofMouseEventArgs& rArgs);
	void mouseDragged(ofMouseEventArgs& rArgs);
	void windowResized(ofResizeEventArgs& rArgs);
	
};
#endif
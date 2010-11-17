#ifndef OFXTWEAKBARSTORAGEH
#define OFXTWEAKBARSTORAGEH

class ofxTweakbar;

/**
 * Base class for tweakbar storage. A storage class
 * takes care of saving/reloading the values of the GUI 
 * to, for example a .INI or .XML file.
 *
 * Each storage class must be compatible with these virtual
 * functions.
 *
 *
 */
class ofxTweakbarStorage {
public:
	ofxTweakbarStorage(ofxTweakbar* pBar);
	ofxTweakbar* getBar();
	void setBar(ofxTweakbar* pBar);
	virtual void store() = 0;
	virtual void retrieve() = 0;
private:
	ofxTweakbar* bar;
};
#endif

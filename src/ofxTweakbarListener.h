/*
 *  ofxTweakbarListener.h
 *  ofxTweakbar2
 *
 *  Created by Peter Uithoven on 5/13/11.
 */

#ifndef _ofxTweakbarListener
#define _ofxTweakbarListener

#include "ofMain.h"
#include "ofxTweakbar.h"

class ofxTweakbarListener
{
	public:
		virtual void onChange(ofxTweakbar * bar) = 0;
};

#endif

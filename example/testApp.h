#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxTweakbarIncludes.h"
#include "ofxIniFile.h"
#include "ofxTweakbarINI.h"


class testApp : public ofBaseApp{

	public:
		testApp();
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		static void TW_CALL buttonCallback(void* pApp);
		
		ofxTweakbar* settings;
		ofxTweakbar* particles;
		ofxIniFile* ini_file;
		ofxTweakbarINI* ini;
		float test_value_a;
		bool test_bool_a;
		int test_standard_int;
		float dir[3];
		float colors[3];
		int num_particles;
		
		bool bool_a;
		bool bool_b;
		int num_files;
		int num_textures;
		float tweak;
};

#endif

#include "testApp.h"

testApp::testApp()
{
	// Create two tweakbars.
	settings = ofxTweakbars::create("settings", "Basic Settings");
	particles = ofxTweakbars::create("particles", "Particles");
	
	// Speed param, between 1 and 100, shortcut key = b
	settings->addInt("speed", &test_standard_int, "min=1 max=100 key=b");
	settings->addVec3f("direction", dir); // TODO: somehow this crashes :C
	settings->addSeparator();  
	settings->addBool("use_delay", &bool_a, "label='Use delay'");
	settings->addBool("use_timeout", &bool_b, "label='Use timeout'");
	settings->addInt("num_files", &num_files, "label='Number of files' min=1 max=1000");
	settings->addFloat("accel_tweak", &tweak)->setLabel("Tweak accel.")->setMin("0.01")->setMax("1.55");

	// Group settings (setGroup(...))
	settings->addColor3f("background_color", colors)
			->setLabel("Colour")
			->setGroup("Particle Settings");
	
	settings->addBool("enabled", &test_bool_a)
			->setGroup("Particle Settings");
			
	// Add a separator. When you want to add it to a group you need to give it
	// a name.
	settings->addSeparator("my_seperator")
			->setGroup("Particle Settings");
			
	// Looooots of setters...
	settings->addFloat(
					"change"
					,&test_value_a
					,"label='Change acceleration' min=0 max=1 step=0.001"
			)
			->setLabel("Another label")
			->setMax("3")
			->setMin("1")
			->setStep("0.1")
			->setInc("=")
			->setDecr("-");
		 
	// Set tweakbar settings.
	settings
		->setSize(200,500)
		->setColor(44,44,44,180)
		->setFontSize(2);
		
	particles->addInt("num_particles", &num_particles);
	
	// Advanced: Use an ini file to store and retrieve the settings.
	ini_file = new ofxIniFile("tweakbar.ini");
	ini = new ofxTweakbarINI(settings, ini_file);
	ini->retrieve();
	
	
	// By default close the particles pane.
	particles
		->setPosition(220,15)
		->setSize(200,500)
		->close();
		
		
	// Advanced: add a callback function. The function buttonCallback is 
	// called when you press the button. 
	settings->addButton(
		"new_files"
		,testApp::buttonCallback
		,this
	)->setLabel("Change number of files");
		
	// By default we use a simple text file to store values automatically
	// when you press the '.' key. Here we load these values. Be sure to 
	// call load() after you've added all your variables.
	particles->load();
	settings->load();
			
}

void TW_CALL testApp::buttonCallback(void* pApp) {
	testApp* app = static_cast<testApp*>(pApp);
	app->num_files = 500;
	app->settings->refresh();
}

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofxTweakbars::draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 's') {
		// Store the values into an ini file.
		ini->store();
	}
	else if(key == 'r') {
		// Retrieve the values.
		ini->retrieve();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


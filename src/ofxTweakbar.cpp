#include "ofMain.h"
#include "ofxTweakbar.h"
#include "ofxTweakbars.h"
#include <sstream>

void TW_CALL ofxtweakbar_loadclick(void* pTweakbar) {
	ofxTweakbar* bar = static_cast<ofxTweakbar*>(pTweakbar);
	string load_file = bar->getFile("ofxtweakbar_file")->getSelectedFileName();
	if(load_file != "") {
		ofxTweakbars::load(bar, load_file);
	}
};

void TW_CALL ofxtweakbar_saveclick(void* pTweakbar) {
	ofxTweakbar* bar = static_cast<ofxTweakbar*>(pTweakbar);
	ofxTweakbars::save(bar, bar->getString("ofxtweakbar_fileame"));
}

ofxTweakbar::ofxTweakbar(
	 std::string sName
	,std::string sTitle
	,bool bAutoStore
	,ofxTweakbars* pTweakbars
	,bool isGlobal
)
:name(sName) // TODO maybe a bit redundant (used by storages)
,title(sTitle)
,use_autostore(bAutoStore)
,tweakbars(pTweakbars)
,is_global(isGlobal)
{
	// is_global is a kind of hackery flag. I added a global "gui" instance
	// which actually can only be created after ofxTweakbars (note the "s") 
	// has been initialized. I had to add some swizzles to check this).
	if(!is_global) {
		init();
	}
}

void ofxTweakbar::init() {
	// make sure to remove non-alpha chars from the tweakbar name
	std::string clean_name;
	for(int i = 0; i < name.size(); ++i) {
		if(isalnum(name[i])) {
			clean_name.push_back(name[i]);
		}
	}

	if(clean_name.size() == 0) {
		throw "Error while creating a tweakbar; use a normal name :)";
	}
	name = clean_name;
	filename = name +".dat";
	bar = TwNewBar(name.c_str());
	setLabel(title);
	
	// TODO: We need only one BarData and let it store all properties!!
	// create a data storage for the position.
	position = new ofxTweakbarBarData(this, "bardata_position");
	position->setType(OFX_TW_TYPE_BAR_POSITION);
	variables["bardata_position"] = position;	

	// create a data storage for the size
	size = new ofxTweakbarBarData(this, "bardata_size");
	size->setType(OFX_TW_TYPE_BAR_SIZE);
	variables["bardata_size"] = size;

	// check if we are open or closed
	size = new ofxTweakbarBarData(this, "bardata_opened");
	size->setType(OFX_TW_TYPE_BAR_OPENED);
	variables["bardata_opened"] = size;
	
	// create data storage for values width
	values_width = new ofxTweakbarBarData(this, "bardata_valueswidth");
	values_width->setType(OFX_TW_TYPE_BAR_VALUES_WIDTH);
	variables["bardata_valueswidth"] = values_width;
	
	// make sure the gui doesnt leave the window.
	TwDefine(" GLOBAL contained=true ");
	
	setColor(44,44,44,200);
	setFontSize(2);
}

// TODO figure out how to handle the global gui object
ofxTweakbar::~ofxTweakbar() {
	std::map<std::string, ofxTweakbarType*>::iterator it = variables.begin();
	while(it != variables.end()) {
		delete it->second;
		++it;
	}
}

void ofxTweakbar::draw() {
	if(!is_global) {
		return;
	}
	checkInit();
	ofxTweakbars::draw();
}

void ofxTweakbar::checkInit() {
	if(!ofxTweakbars::getInstance()->isInitialized()) {
		ofxTweakbars::getInstance()->init();
		ofxTweakbars::getInstance()->addTweakbarToList(name, this);
		init();
	}
}

ofxTweakbar* ofxTweakbar::setSize(int nWidth, int nHeight) {
	ostringstream oss;
	oss << getName() << " size='" << nWidth << " " << nHeight << "'";
	TwDefine(oss.str().c_str());
	return this;
}
	
ofxTweakbar* ofxTweakbar::setColor(int nR, int nG, int nB, int nAlpha) {
	ostringstream oss;
	oss << getName() << " color='" << nR << " " << nG << " " << nB << "' alpha=" << nAlpha;
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setFontSize(int nSize) {
	ostringstream oss;
	oss << getName() << " fontsize=" << nSize;
	TwDefine(oss.str().c_str());
	return this;
}


ofxTweakbar* ofxTweakbar::setIconifiable(bool flag) {
	ostringstream oss; 
	oss << getName() << " iconifiable=" << ((flag) ? "true" : "false");
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setMovable(bool flag) {
	ostringstream oss; 
	oss << getName() << " movable=" << ((flag) ? "true" : "false");
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setResizable(bool flag) {
	ostringstream oss; 
	oss << getName() << " resizable=" << ((flag) ? "true" : "false");
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setFontResizable(bool flag) {
	ostringstream oss; 
	oss << getName() << " fontresizable=" << ((flag) ? "true" : "false");
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setLabel(std::string sLabel) {
	ostringstream oss;
	oss << getName() << " label='" << sLabel << "'";
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setPosition(float nX, float nY) {
	ostringstream oss;
	oss << getName() << " position='" << nX << " " << nY << "'";
	TwDefine(oss.str().c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::setValuesWidth(int nWidth) {
	ostringstream oss;
	oss << getName() << " valueswidth='" << nWidth << "'";
	TwDefine(oss.str().c_str());
}

ofxTweakbar* ofxTweakbar::fitValues() {
	ostringstream oss;
	oss << getName() << " valueswidth='fit'";	
	TwDefine(oss.str().c_str());
}

// load stored state
ofxTweakbar* ofxTweakbar::load() {
	ofxTweakbars::load(this);
}

TwBar* ofxTweakbar::getBar() {
	return bar;
}

ofxTweakbarFloat* ofxTweakbar::addFloat(
	 const char* pName
	,float& pValue
	,const char* pDef
)
{
	return addFloat(pName, &pValue, pDef);
}

ofxTweakbarFloat* ofxTweakbar::addFloat(
		const char* pName
		,void* pValue
		,const char* pDef
) 
{
	checkInit();
	ofxTweakbarFloat* type = new ofxTweakbarFloat(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_FLOAT, pValue, pDef);
	variables[type->getName()] = type;
	type->setLabel(pName);
	return type;
}

ofxTweakbarBool* ofxTweakbar::addBool(
	const char* pName
	,bool& pValue
	,const char* pDef
)
{
	return addBool(pName, &pValue, pDef);
}

ofxTweakbarBool* ofxTweakbar::addBool(
		 const char* pName
		,void *pValue
		,const char* pDef
)
{
	checkInit();
	ofxTweakbarBool* type = new ofxTweakbarBool(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_BOOLCPP, pValue, pDef);
	variables[type->getName()] = type;
	type->setLabel(pName);
	return type;
}


ofxTweakbarInt* ofxTweakbar::addInt(
		const char* pName
		,int& pValue
		,const char* pDef
)
{	
	return addInt(pName, &pValue, pDef);
}
	

ofxTweakbarInt* ofxTweakbar::addInt(
		 const char* pName
		,void *pValue
		,const char* pDef
)
{
	checkInit();
	ofxTweakbarInt* type = new ofxTweakbarInt(this, pName, pValue);
	TwAddVarRW(bar,type->getName(), TW_TYPE_INT32, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarVec3f* ofxTweakbar::addVec3f(
		const char* pName
		,void *pValue
		,const char* pDef 
)
{
	checkInit();
	ofxTweakbarVec3f* type = new ofxTweakbarVec3f(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_DIR3F, pValue,pDef);
	variables[type->getName()] = type;
	type->setLabel(pName);
	return type;
}

ofxTweakbarQuat4f* ofxTweakbar::addQuat4f(
		const char* pName
		,void *pValue
		,const char *pDef
) 
{
	checkInit();
	ofxTweakbarQuat4f* type = new ofxTweakbarQuat4f(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_QUAT4F, pValue,pDef);
	variables[type->getName()] = type;
	type->setLabel(pName);
	return type;
}


ofxTweakbarColor3f* ofxTweakbar::addColor3f(
 		 const char* pName
		,void *pValue
		,const char *pDef
)
{
	checkInit();
	ofxTweakbarColor3f* type = new ofxTweakbarColor3f(this, pName, pValue);
	TwAddVarRW(bar, type->getName(), TW_TYPE_COLOR3F, pValue, pDef);
	variables[type->getName()] = type;
	type->setLabel(pName);
	return type;
}

ofxTweakbarString* ofxTweakbar::addString(
	const char* pName
	,string& pValue
	,const char* pDef 
)
{	
	return addString(pName, &pValue, pDef);
}

ofxTweakbarString* ofxTweakbar::addString(
	const char* pName
	,void *pValue
	,const char* pDef 
)
{
	checkInit();
	ofxTweakbarString* type = new ofxTweakbarString(this, pName, pValue);
	variables[type->getName()] = type;
	TwAddVarRW(bar, type->getName(), TW_TYPE_STDSTRING, pValue, pDef);
	type->setLabel(pName);
	return type;
}

ofxTweakbarFiles* ofxTweakbar::addFiles(
		 const char* pName
		,void *pValue
		,const char* pDef 
)
{
	checkInit();
	ofxTweakbarFiles* type = new ofxTweakbarFiles(this, pName, pValue, pDef);
	variables[type->getName()] = type;
	return type;
}

ofxTweakbarSeparator* ofxTweakbar::addSeparator(
		 const char*  pName
		,const char* pDef 
) 
{
	checkInit();
	ofxTweakbarSeparator* type = new ofxTweakbarSeparator(this, pName);
	variables[type->getName()] = type;
	TwAddSeparator(bar, type->getName(), pDef);
	return type;
}

ofxTweakbarButton* ofxTweakbar::addButton(
		const char* pName
		,TwButtonCallback fCallback
		,void* pClientData 
		,const char* pDef 
)
{
	checkInit();
	ofxTweakbarButton* type = new ofxTweakbarButton(this, pName);
	TwAddButton(bar, type->getName(), fCallback, pClientData, pDef);
	variables[type->getName()] = type;
	type->setLabel(pName);
	return type;
}


ofxTweakbarList* ofxTweakbar::addList(
		const char* pName
		,int& pValue
		,const char* pDef 
)
{
	return addList(pName, &pValue, pDef);
}

// we assume pDef has a value like: "option one, option two, option three"
// or, you can use the addOption function of ofxTweakbarList.
ofxTweakbarList* ofxTweakbar::addList(
		const char* pName
		,void* pValue
		,const char* pDef 
)
{
	checkInit();

	ofxTweakbarList* type = new ofxTweakbarList(this, pName, pValue, pDef);

	// since 1.14 we have TwDefineEnumFromString.
	TwType enum_type;
	enum_type = TwDefineEnumFromString(pName, pDef);
	TwAddVarRW(bar, type->getName(),enum_type, pValue, NULL);

	variables[type->getName()] = type;
	return type;
}

ofxTweakbar* ofxTweakbar::addLoader(string sPath, string sExt) {
	if(sPath == "") {
		sPath = ofToDataPath(".", true);
	}
	checkInit();
	addFiles("ofxtweakbar_file", NULL)
		->setPath(sPath,sExt)
		->create()
		->setLabel("Select file ...");
	addButton("load", ofxtweakbar_loadclick, this)->setLabel("LOAD");	
	return this;
}

ofxTweakbar* ofxTweakbar::addSaver() {
	checkInit();
	addString("ofxtweakbar_filename",&filename)->setLabel("Save settings as");
	addButton("Save", ofxtweakbar_saveclick, this)->setLabel("SAVE");
	return this;
}

std::map<std::string, ofxTweakbarType*> ofxTweakbar::getVariables() {
	return variables;
}

std::string ofxTweakbar::getName() {
	return name;
}

std::string ofxTweakbar::getFileName() {
	return filename;
}

void ofxTweakbar::setFileName(std::string sFileName) {
	filename = sFileName;
}

bool ofxTweakbar::useAutoStore() {
	return use_autostore;
}

ofxTweakbar* ofxTweakbar::open() {
	std::string cmd = getName() +" iconified=false";
	TwDefine(cmd.c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::close() {
	std::string cmd = getName() +" iconified=true";
	TwDefine(cmd.c_str());
	return this;
}

ofxTweakbar* ofxTweakbar::refresh() {
	TwRefreshBar(getBar());
	return this;
}

string ofxTweakbar::getString(string sName) {
	map<string, ofxTweakbarType*>::const_iterator it =  variables.find(sName);
	if(it != variables.end()) {
		ofxTweakbarString* str = static_cast<ofxTweakbarString*>(it->second);
		return str->getValue();
	}
	return "";
}

ofxTweakbarFiles* ofxTweakbar::getFile(string sName) {
	map<string, ofxTweakbarType*>::iterator it =  variables.find(sName);
	if(it != variables.end()) {
		ofxTweakbarFiles* type = static_cast<ofxTweakbarFiles*>(it->second);
		return type;
	}
	return NULL;
}

ofxTweakbar* ofxTweakbar::setButtonAlign(int align) {
	string bt_align = "GLOBAL buttonalign=left";
	if(align == CENTER) {
		bt_align = "GLOBAL buttonalign=center";
	}
	else if(align == RIGHT) {
		bt_align = "GLOBAL buttonalign=right";
	}
	TwDefine(bt_align.c_str());
	return this;
}


#include "ofxScene.h"

//--------------------------------------------------------------
ofxScene::ofxScene()
    : bSetup(false)
{
    ofLogVerbose() << "ofxScene Constructor";
}

//--------------------------------------------------------------
ofxScene::~ofxScene()
{
    ofLogVerbose() << "ofxScene Destructor :: " << sceneID;
}

//--------------------------------------------------------------
void ofxScene::setup()
{
    if (bSetup) return;

    ofLogVerbose() << "ofxScene setup :: " << sceneID;

    selfSetup();

    bSetup = true;
}

//--------------------------------------------------------------
void ofxScene::exit()
{
    if (!bSetup) return;
    
    ofLogVerbose() << "ofxScene setup :: " << sceneID;

    selfExit();
    
    bSetup = false;
}

//--------------------------------------------------------------
void ofxScene::update(float dt)
{
    selfUpdate(dt);
}

//--------------------------------------------------------------
void ofxScene::draw()
{
    selfDraw();
}

//--------------------------------------------------------------
int ofxScene::getSceneID()
{
    return sceneID;
}

//--------------------------------------------------------------
ofxSceneManager * ofxScene::getManager()
{
    return manager;
}

//--------------------------------------------------------------
void ofxScene::setSceneID( int s )
{
    sceneID = s;
}

//--------------------------------------------------------------
void ofxScene::setManager( ofxSceneManager *sm )
{
    manager = sm;
}
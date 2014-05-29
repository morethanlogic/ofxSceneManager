#include "ofxScene.h"

//--------------------------------------------------------------
ofxScene::ofxScene()
    : bSetup(false)
{
    printf("ofxScene Constructor \n");
}

//--------------------------------------------------------------
ofxScene::~ofxScene()
{
    printf("ofxScene Destructor :: %d\n", sceneID);
}

//--------------------------------------------------------------
void ofxScene::setup()
{
    if (bSetup) return;

    printf("ofxScene setup :: %d\n", sceneID);

    selfSetup();

    bSetup = true;
}

//--------------------------------------------------------------
void ofxScene::exit()
{
    if (!bSetup) return;
    
    printf("ofxScene setup :: %d\n", sceneID);

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
/*
 *  ofxScene.h
 *  Cocoa Test
 *
 *  Created by Oriol Ferrer Mesià on 28/10/09.
 *  Copyright 2009 uri.cat. All rights reserved.
 *
 */

/**
 
 Mainly an abstract class, to define a protocol for custom "ofxScene" subclasses
 
 **/

#ifndef ofxScene_h
#define ofxScene_h

//#include "ofxSceneManager.h"
#include "ofMain.h"

class ofxSceneManager;

class ofxScene{

public:

    ofxScene();
    ~ofxScene();

    void setup();
    void exit();
    
    void update(float dt);
    void draw();
    
    int getSceneID();
    ofxSceneManager * getManager();
    
    // ---
    // Virtuals Methods
    virtual void selfSetup() {}
    virtual void selfExit() {}
    
    virtual void selfUpdate(float dt){} ;
    virtual void selfDraw(){};

    virtual void showUI(){}
    virtual void hideUI(){}

    virtual void pauseScene(){}
    virtual void resumeScene(){}

    //notifications
    virtual void sceneWillAppear( ofxScene * fromScreen ) { printf("ofxScene::sceneWillAppear() :: %d\n", sceneID); };
    virtual void sceneDidAppear() { printf("ofxScene::sceneDidAppear() :: %d\n", sceneID); };
    virtual void sceneWillDisappear( ofxScene * toScreen) { printf("ofxScene::sceneWillDisappear() :: %d\n", sceneID); };
    virtual void sceneDidDisappear( ofxScene * fromScreen ) { printf("ofxScene::sceneDidDisappear() :: %d\n", sceneID); };

    //events - desktop
    virtual void keyPressed(int key) {} ;
    virtual void keyReleased(int key) {};
    virtual void mouseMoved(int x, int y ) {};
    virtual void mouseDragged(int x, int y, int button) {};
    virtual void mousePressed(int x, int y, int button) {};
    virtual void mouseReleased(int x, int y, int button) {};
    virtual void windowResized(int w, int h){};

    //touch events - iphone
    #ifdef TARGET_OF_IPHONE
    virtual void touchDown(ofTouchEventArgs &touch){};
    virtual void touchMoved(ofTouchEventArgs &touch){};
    virtual void touchUp(ofTouchEventArgs &touch){};
    virtual void touchDoubleTap(ofTouchEventArgs &touch){};
    virtual void touchCancelled(ofTouchEventArgs &touch){};
    #endif

    //visual debug
    virtual void drawDebug(){ ofDrawBitmapString( "I am Scene: " + ofToString(sceneID), ofGetWidth() - 200, 20); }

protected:
    bool bSetup;

private:

    friend class ofxSceneManager;
    void setSceneID( int s );
    void setManager( ofxSceneManager *sm );

    int sceneID;
    ofxSceneManager * manager;
};

#endif


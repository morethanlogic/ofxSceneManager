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

		ofxScene(){ printf("ofxScene Constructor \n"); };	
		virtual ~ofxScene() { printf("ofxScene Destructor :: %s\n", screenID.c_str()); }

		virtual void setup(){ printf("ofxScene setup :: %s\n", screenID.c_str()); };
		
		virtual void update(float){} ;
		virtual void draw(){};

		//notifications
		virtual void screenWillAppear( ofxScene * fromScreen ) { printf("ofxScene::screenWillAppear() :: %s\n", screenID.c_str()); };
		virtual void screenDidAppear() { printf("ofxScene::screenDidAppear() :: %s\n", screenID.c_str()); };
		virtual void screenWillDisappear( ofxScene * toScreen) { printf("ofxScene::screenWillDisappear() :: %s\n", screenID.c_str()); };
		virtual void screenDidDisappear( ofxScene * fromScreen ) { printf("ofxScene::screenDidDisappear() :: %s\n", screenID.c_str()); };
	
		//events
		virtual void keyPressed(int key) {} ;
		virtual void keyReleased(int key) {};
		virtual void mouseMoved(int x, int y ) {};
		virtual void mouseDragged(int x, int y, int button) {};
		virtual void mousePressed(int x, int y, int button) {};
		virtual void mouseReleased(int x, int y, int button) {};
		virtual void windowResized(int w, int h){};

		//TODO - touch events!
	
		//visual debug
		virtual void drawDebug(){ ofDrawBitmapString( "I am screen: " + screenID, ofGetWidth() - 200, 20); }
	
		string getScreenID(){ return screenID;}
		
	private:

		friend class ofxSceneManager;
		void setScreenID( string s ){ screenID = s; }
		void setManager( ofxSceneManager *sm ){ manager = sm; }
	
		string screenID;
		ofxSceneManager * manager;
};

#endif

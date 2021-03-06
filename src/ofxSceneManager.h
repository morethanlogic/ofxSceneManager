/*
 *  ofxSceneManager.h
 *
 *  Created by Oriol Ferrer Mesià on 02/11/09.
 *  Copyright 2009 uri.cat. All rights reserved.
 *
 */

#ifndef ofxSceneManager_h
#define ofxSceneManager_h

#define MAX_HISTORY	10
#define NULL_SCENE -1

#include "ofMain.h"
#include "ofxScreenCurtain.h"
#include "ofxScene.h"
#include <map>

class ofxScene;

class ofxSceneManager{

	public:

		static ofxSceneManager* instance();
		~ofxSceneManager();
	
		void update(float dt = (ofGetLastFrameTime() / 1000.0f));
		void draw();
	
		void addScene( ofxScene* newScene, int sceneID );
		
		bool goToScene( int sceneID, bool regardless = false, bool doTransition = true );

		bool isTransitioning(){ return !curtain.isReady(); }

		//events - desktop
        void keyPressed(ofKeyEventArgs& args);
        void keyReleased(ofKeyEventArgs& args);
        void mouseDragged(ofMouseEventArgs& args);
        void mouseMoved(ofMouseEventArgs& args);
        void mousePressed(ofMouseEventArgs& args);
        void mouseReleased(ofMouseEventArgs& args);
    
		void windowResized(ofResizeEventArgs& args);
		
		//touch events - ios
		#ifdef TARGET_OF_IPHONE
		void touchDown(ofTouchEventArgs &touch);
		void touchMoved(ofTouchEventArgs &touch);
		void touchUp(ofTouchEventArgs &touch);
		void touchDoubleTap(ofTouchEventArgs &touch);
		void touchCancelled(ofTouchEventArgs &touch);
		#endif
	
		//debug
		void setDrawDebug(bool debug){ drawDebugInfo = debug; }
		bool getDrawDebug(){ return drawDebugInfo; }
	
		//settings
        void setCurtainColor(ofColor color);
        void setCurtainSize(ofRectangle rect);
		void setCurtainDropTime(float t);
		void setCurtainStayTime(float t);
		void setCurtainRiseTime(float t);
		void setCurtainTimes(float drop, float stay, float rise);
		void setOverlapUpdate(bool o); // if true, we will update both scenes while transitioning, otherwise just one at a time

		int getNumScenes();
		ofxScene * getCurrentScene();
		ofxScene * getScene(int sceneID);
		int getCurrentSceneID();
	
	private:

		ofxSceneManager(); // use ofxSceneManager::instance() instead!
		static ofxSceneManager* singleton;

		void updateHistory( ofxScene* );
		void drawDebug();
	
		map <int, ofxScene *>		scenes; //fast access to scene by sID
			
		ofxScene*					currentScene;
		ofxScene*					futureScene;
	
		bool						overlapUpdate; // if true, we will update both scenes when transitioning 
		bool 						drawDebugInfo;

		vector <ofxScene*>			history;

		ofxScreenCurtain			curtain;
		float						curtainDropTime;
		float						curtainStayTime;
		float						curtainRiseTime;
};

#endif

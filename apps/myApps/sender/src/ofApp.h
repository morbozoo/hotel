#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345

class ofApp : public ofBaseApp{

	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		ofTrueTypeFont		font;

	private:
		
		ofxOscSender sender;	
};

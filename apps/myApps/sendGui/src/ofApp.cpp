 
/*
 
 Copyright 2007, 2008 Damian Stewart damian@frey.co.nz
 Distributed under the terms of the GNU Lesser General Public License v3
 
 This file is part of the ofxOsc openFrameworks OSC addon.
 
 ofxOsc is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 ofxOsc is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with ofxOsc.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground( 0, 0, 0 );

	// open an outgoing connection to HOST:PORT
	sender.setup( HOST, PORT );

	mHideGUI = false;	
	width.set("WIDTH",1,1,10);
	setupGUI();
}

//--------------------------------------------------------------
void ofApp::setupGUI(){
	gui.setup("GUI");
	gui.add(width);
}

//--------------------------------------------------------------
void ofApp::changeWidth(int width){

}
//--------------------------------------------------------------
void ofApp::update(){
	
}


//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
	ofTranslate(400, 0, 0);
	// display instructions
	char buf[256];
	sprintf( buf, "sending osc messages to %s:%d", HOST, PORT );
	ofDrawBitmapString( buf, 10, 20 );
	ofDrawBitmapString( "move the mouse to send osc message [/mouse/position <x> <y>]", 10, 50 );
	ofDrawBitmapString( "click to send osc message [/mouse/button <button> <\"up\"|\"down\">]", 10, 65 );
	ofDrawBitmapString( "press A to send osc message [/test 1 3.5 hello <time>]", 10, 80 );
	ofDrawBitmapString( "press B to send osc bundle [ [/bundle1 3] [/bundle2 5.5]\n    [ [/bundle3a nested_bundle_test] [/bundle3b test2] ] ]", 10, 95 );
	ofPopMatrix();
gui.draw();

}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	if ( key =='a' || key == 'A' )
	{
		ofxOscMessage m;
		m.setAddress( "/test" );
		m.addIntArg( 1 );
		m.addFloatArg( 3.5f );
		m.addStringArg( "hello" );
		m.addFloatArg( ofGetElapsedTimef() );
		sender.sendMessage( m );
	}
	else if ( key == 'b' || key == 'B' )
	{
		ofxOscBundle b;
		
		// make message
		ofxOscMessage m;
		m.setAddress( "/bundle1" );
		m.addIntArg( 3 );
		// add to bundle
		b.addMessage( m );

		// and repeat
		m.clear();
		m.setAddress( "/bundle2" );
		m.addFloatArg( 5.5f );
		// add to bundle
		b.addMessage( m );
		
		// make nested bundle
		ofxOscBundle nested_b;
		m.clear();
		m.setAddress( "/bundle3a" );
		m.addStringArg( "nested bundle test" );
		nested_b.addMessage( m );
		m.clear();
		m.setAddress( "/bundle3b" );
		m.addStringArg( "test2" );
		nested_b.addMessage( m );
		
		// add to outer bundle
		b.addBundle( nested_b );

		// send
		sender.sendBundle( b );
	}
		
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	ofxOscMessage m;
	m.setAddress( "/mouse/position" );
	m.addIntArg( x );
	m.addIntArg( y );
	sender.sendMessage( m );
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress( "/mouse/button" );
	m.addStringArg( "down" );
	sender.sendMessage( m );
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
	ofxOscMessage m;
	m.setAddress( "/mouse/button" );
	m.addStringArg( "up" );
	sender.sendMessage( m );	
}

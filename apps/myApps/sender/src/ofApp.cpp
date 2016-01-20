
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

	ofBackground( 40, 100, 40 );

	// open an outgoing connection to HOST:PORT
	sender.setup( HOST, PORT );
}

//--------------------------------------------------------------
void ofApp::update(){
	
}


//--------------------------------------------------------------
void ofApp::draw(){
	// display instructions
	char buf[256];
	sprintf( buf, "sending osc messages to %s:%d", HOST, PORT );
	ofDrawBitmapString( buf, 10, 20 );
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	if ( key =='a' || key == 'A' )
	{
		ofxOscMessage m;
		m.setAddress( "mood" );
		m.addInt64Arg( 0 );
		sender.sendMessage( m );
	}else if( key =='s' || key == 'S' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 1 );
                sender.sendMessage( m );
        }else if( key =='d' || key == 'D' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 2 );
                sender.sendMessage( m );
        }else if( key =='f' || key == 'F' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 3 );
                sender.sendMessage( m );
        }else if( key =='q' || key == 'Q' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 4 );
                sender.sendMessage( m );
        }else if( key =='w' || key == 'W' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 5 );
                sender.sendMessage( m );
        }else if( key =='e' || key == 'E' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 6 );
                sender.sendMessage( m );
        }else if( key =='r' || key == 'R' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 7 );
                sender.sendMessage( m );
        }else if( key =='T' || key == 't' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 8 );
                sender.sendMessage( m );
        }else if( key =='Y' || key == 'y' )
        {
                ofxOscMessage m;
                m.setAddress( "mood" );
                m.addInt64Arg( 9 );
                sender.sendMessage( m );
        }
		
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
        if(x < 256){
            ofxOscMessage m;	
	    m.setAddress( "slider1" );
            m.addInt64Arg( x );
	    sender.sendMessage( m );
	}
	if(y < 256){
            ofxOscMessage m;
            m.setAddress( "slider2" );
            m.addInt64Arg( y );
            sender.sendMessage( m );
        }
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


#include "Masker.h"

//--------------------------------------------------------------
void Masker::setup(){
    particleAddedL = false;
    particleAddedR = false;
    left.push_back(ofVec3f(0, 768, 0));
    left.push_back(ofVec3f(0, 0, 0));
    left.push_back(ofVec3f(512, 0, 0));

    right.push_back(ofVec3f(1024, 768, 0));
    right.push_back(ofVec3f(1024, 0, 0));
    right.push_back(ofVec3f(512, 0, 0));
}

//--------------------------------------------------------------
void Masker::update(){
}

//--------------------------------------------------------------
void Masker::draw(){
    ofPushStyle();
    ofSetColor(55, 55, 55, 55);
    ofSetLineWidth(3);
    glBegin(GL_POLYGON);
    for(int i = 0; i < left.size(); i ++){
        glVertex3f(left[i].x, left[i].y, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i = 0; i < right.size(); i ++){
        glVertex3f(right[i].x, right[i].y, 0.0f);
    }
    glEnd();

    ofPopStyle();
}

//--------------------------------------------------------------
void Masker::addParticleL(ofVec3f posL){
    if(particleAddedL){
	left.pop_back();
	//left.pop_back();
    }
    left.push_back(posL);
    left.push_back(ofVec3f(512, 768, 0));
    //left.push_back(ofVec3f(0, 768, 0));
    particleAddedL = true;
}

//--------------------------------------------------------------
void Masker::addParticleR(ofVec3f posR){
    if(particleAddedR){
	right.pop_back();
    }
    right.push_back(posR);
    left.push_back(ofVec3f(512, 768, 0));
    particleAddedR = true;
}

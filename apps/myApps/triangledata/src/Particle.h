/*
Particle by Thomas Sanchez Lengeling
*/

#pragma once

#include "ofMain.h"

namespace tri{
  class Particle;

  typedef std::shared_ptr<Particle> ParticleRef;

  class Particle{
  public:

     Particle( const Particle & obj){
        mPos = obj.mPos;
        mVel = obj.mVel;
        mCol = obj.mCol;
        mParticleIndex = obj.mParticleIndex;
     }

    Particle(){
        mParticleIndex = -1;
        mCol = ofColor(255);
    }

    static ParticleRef create(){
        return std::make_shared<Particle>();
    }

    void setPosition(const ofVec3f & pos){
        mPos = pos;
    }

    void addVelocity(const ofVec3f & vel){
        mVel = vel;
    }

    void setColor(ofColor col){
        mCol = col;
    }

    void setParticleId(int index){
        mParticleIndex = index;
    }

    int getParticleId(){
      return mParticleIndex;
    }

    ofVec3f getPosition(){
        return mPos;
    }

    void drawPoint(){
        ofSetColor(mCol);
        ofEllipse(mPos.x, mPos.y, 10, 10);
    }

  private:
    ofVec3f     mPos;
    ofVec3f     mVel;
    ofColor     mCol;

    int         mParticleIndex;
  };
}

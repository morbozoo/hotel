#include "ParticleManager.h"


namespace tri{

  void ParticleManager::drawPoints()
  {
    for(auto & particle : mParticles){
      particle->drawPoint();
      ofSetColor(ofColor(255, 0, 0));
      ofDrawBitmapString(" "+ofToString(particle->getParticleId()), particle->getPosition().x + 5, particle->getPosition().y );
    }
  }

  void ParticleManager::drawTriangleMesh()
  {


  }

  void ParticleManager::updateMesh()
  {

  }

  Particle * ParticleManager::getNearestParticle(ofVec3f pos)
  {
    Particle * mTempP = NULL;
    int index = -1;
    for(auto & particle : mParticles){
     if(particle->getPosition().distance(pos) < 15){
       index = particle->getParticleId();
       return particle;
     }
    }
    return mTempP;
  }

    Particle * ParticleManager::getParticle(int index){
      return mParticles.at(index);
    }

    void ParticleManager::updateParticlePos(int index, ofVec3f pos){
        mParticles.at(index)->setPosition(pos);
    }

    void ParticleManager::updateParticleColor(int index, ofColor col){
        mParticles.at(index)->setColor(col);
    }

  void ParticleManager::addParticle(Particle * particle)
  {
    particle->setParticleId(mParticles.size());
    mParticles.push_back(particle);
  }



}

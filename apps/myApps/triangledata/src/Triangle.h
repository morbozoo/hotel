#pragma once

#include "ofMain.h"
#include "Particle.h"

namespace tri{

  class Triangle{
    public:
      Triangle(){}

      Particle * getParticleA(){return mParticleA;}
      Particle * getParticleB(){return mParticleB;}
      Particle * getParticleC(){return mParticleC;}

      void setParticleA( Particle * pa){mParticleA = pa;}
      void setParticleB( Particle * pb){mParticleB = pb;}
      void setParticleC( Particle * pc){mParticleC = pc;}

    private:

        Particle * mParticleA;
        Particle * mParticleB;
        Particle * mParticleC;
  };

}

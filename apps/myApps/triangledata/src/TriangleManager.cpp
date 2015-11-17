#include "TriangleManager.h"

namespace tri{


    void TriangleManager::addTriangle(Triangle * tri){
        std::cout<<"A "<<tri->getParticleA()->getParticleId()<<std::endl;
        std::cout<<"B "<<tri->getParticleB()->getParticleId()<<std::endl;
        std::cout<<"C "<<tri->getParticleC()->getParticleId()<<std::endl;
        mTriangles.push_back(tri);
    }

    void TriangleManager::drawMesh(){

      //  ofSetColor(ofColor(0, 100, 150, 100));
      //  mMesh.drawFaces();

        ofSetColor(ofColor(0, 200, 150, 70));
        mMesh.draw();

    }




    void TriangleManager::renderMesh(){

        mMesh.clear();
        mMesh.setMode(OF_PRIMITIVE_TRIANGLES);

        for(auto & particle : mParticles){
            mMesh.addVertex( ofPoint( particle->getPosition().x, particle->getPosition().y));
        }

        for(auto & tri : mTriangles){
            mMesh.addIndex(tri->getParticleA()->getParticleId());
            mMesh.addIndex(tri->getParticleB()->getParticleId());
            mMesh.addIndex(tri->getParticleC()->getParticleId());

            std::cout<<"A :"<<tri->getParticleA()->getParticleId()<<std::endl;
            std::cout<<"B :"<<tri->getParticleB()->getParticleId()<<std::endl;
            std::cout<<"C :"<<tri->getParticleC()->getParticleId()<<std::endl;
        }





    }

}

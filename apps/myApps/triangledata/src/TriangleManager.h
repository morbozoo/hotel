#pragma once

#include "ofMain.h"

#include "Triangle.h"
#include  "ParticleManager.h"

namespace tri{

  class TriangleManager;
  class ImageCollection;

  typedef std::shared_ptr<TriangleManager> TriangleManagerRef;

  class ImageCollection{
    public:

        void addImage(ofImage img){
          mImages.push_back(img);
        }

        ofColor getColor(int i, int x, int y){
          return mImages.at(i).getColor(x, y);
        }

    private:
        std::vector<ofImage> mImages;

  };


  class TriangleManager : public ParticleManager, public ImageCollection {
    public:
      static  TriangleManagerRef create(){
        return std::make_shared<TriangleManager>();
      }

      void drawMesh();
      void renderMesh();

      void addTriangle(Triangle * tri);
    private:

      std::vector<Triangle *> mTriangles;

      ofMesh                  mMesh;
  };

}

#include "ofApp.h"

using namespace tri;

//--------------------------------------------------------------
void ofApp::setup(){

  //mParticleManager = ParticleManager::create();
  mTriangleManager = TriangleManager::create();
  enableCreateTriangle = false;
  enableMoveParticles  = false;
  enableNewParticle    = false;

  triangleCounter      = 0;

  setupGUI();
  setupOSC();
}

void ofApp::setupGUI(){



    mButtonXMLSave.addListener(this,&ofApp::saveGUIValues);
    mButtonOSC.addListener(this, &ofApp::setupOSC);

    gui.setup("GUI");
    gui.add(mButtonXMLSave.setup("mButtonXMLSave"));

    gui.add(mPortSlider.setup("Port", 36000, 12000, 90000));
    gui.add(mHostSlider01.setup("Host 01", 192, 0, 255));
    gui.add(mHostSlider02.setup("Host 02", 168, 0, 255));
    gui.add(mHostSlider03.setup("Host 03", 1, 0, 255));
    gui.add(mHostSlider04.setup("Host 04", 1, 0, 255));
    gui.add(mButtonOSC.setup("Setup OSC"));
    bHide = true;

    gui.loadFromFile("settings.xml");
}

void ofApp::saveGUIValues(){
    std::cout<<"saving file"<<std::endl;
    gui.saveToFile("settings.xml");
}

void   ofApp::setupOSC(){

    std::string host = ofToString((int)mHostSlider01)+"."+ofToString((int)mHostSlider02)+"."+ofToString((int)mHostSlider03)+"."+ofToString((int)mHostSlider04);
    std::cout<<"setup OSC: "<<host<<" "<<mPortSlider<<std::endl;
	sender.setup(host, mPortSlider);
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

   ofBackground(ofColor(0));

    mTriangleManager->drawMesh();
    mTriangleManager->drawPoints();

    if( !bHide ){
		gui.draw();
	}
}

void ofApp::exit()
{

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 't'){
        enableCreateTriangle = true;
    }
    else if(key == 'm'){
        enableMoveParticles  = true;
    }
    else if(key == 'n'){
        enableNewParticle = true;
    }
    else if(key == 'g'){
        bHide = !bHide;
    }else if(key == '2'){
        gui.loadFromFile("settings.xml");
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 't'){
        enableCreateTriangle = false;
    }
    else if(key == 'm'){
        enableMoveParticles = false;
    }
    else if(key == 'n'){
        enableNewParticle = false;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    if(enableMoveParticles){
        if(mTempParticleId != -1){
           mTriangleManager->updateParticlePos(mTempParticleId, ofVec3f(x, y, 0));
        }
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


    if(enableCreateTriangle){
        Particle * particle = mTriangleManager->getNearestParticle(ofVec3f(x, y, 0));
        //found something
        if(particle != NULL){
            //mParticleManager->updateParticleColor(particle->getParticleId(), ofColor(0, 150, 175));
            particle->setColor( ofColor(0, 150, 175));
            std::cout<<particle->getParticleId()<<std::endl;

            if(triangleCounter == 0)
                mtempTriA = particle->getParticleId();

            if(triangleCounter == 1){
                mtempTriB = particle->getParticleId();
            }

            if(triangleCounter == 2){
                mtempTriC = particle->getParticleId();

                Triangle * tri = new Triangle();
                tri->setParticleA( mTriangleManager->getParticle(mtempTriA) );
                tri->setParticleB( mTriangleManager->getParticle(mtempTriB) );
                tri->setParticleC( mTriangleManager->getParticle(mtempTriC) );
                mTriangleManager->addTriangle(tri);
                mTriangleManager->renderMesh();
            }

            triangleCounter++;
            if(triangleCounter >=3 )
                triangleCounter = 0;
        }
    }
    else if(enableMoveParticles){
        Particle * particle = mTriangleManager->getNearestParticle(ofVec3f(x, y, 0));
        //found something
        if(particle != NULL){
            mTempParticleId = particle->getParticleId();
            mTriangleManager->updateParticlePos(mTempParticleId, ofVec3f(x, y, 0));
        }else{
            mTempParticleId = -1;
        }
    }
    else if(enableNewParticle){
        Particle * particle = new Particle();
        particle->setPosition(ofVec3f(x, y, 0));
        mTriangleManager->addParticle(particle);

    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    if(enableMoveParticles){
        if(mTempParticleId != -1){
           mTriangleManager->updateParticlePos(mTempParticleId, ofVec3f(x, y, 0));
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

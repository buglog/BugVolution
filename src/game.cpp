#include "game.h"

//--------------------------------------------------------------
void Game::setup(){
	ofSetFrameRate(60);
	
	cammy.setup();
}

//--------------------------------------------------------------
void Game::update(){
	
	cammy.direction;
	
	if(left){
		cammy.node.truck(-cammy.speed);
	}
	if(right){
		cammy.node.truck(cammy.speed);
	}
	if(up){
		//cammy.direction += glm::vec3(cammy.pan.getLookAtDir().x,0,cammy.pan.getLookAtDir().z);
		cammy.node.dolly(cammy.speed);
	}
	if(down){
		cammy.node.dolly(-cammy.speed);
	}
	
	// UPDATE POSITION
	cammy.node.dolly(cammy.direction.y);
	cammy.node.dolly(cammy.direction.x);
	
	if(space){
		if(cammy.onGround){
			cammy.Jump();
		}
	}
	ofLog(OF_LOG_NOTICE,"onGround:" + ofToString(cammy.onGround));
	cammy.update();
}

//--------------------------------------------------------------
void Game::draw(){
	
	cammy.ezcam.begin();
	
	ofSetColor(0,0,0);
	ofDrawGrid(5.0f,100,false,false,true,false);
	ofSetColor(0,0,255);
	ofDrawGrid(10.0f,50,false,false,true,false);
	cammy.draw();

	cammy.ezcam.end();
}

//--------------------------------------------------------------
void Game::keyPressed(int key){
	switch(key){
		case OF_KEY_LEFT:
		case 'a':
			left=true;
			break;
		case OF_KEY_RIGHT:
		case 'd':
			right=true;
			break;
		case OF_KEY_UP:
		case 'w':
			up=true;
			break;
		case OF_KEY_DOWN:
		case 's':
			down=true;
			break;
		case ' ':
			space=true;
			break;
	}
}

//--------------------------------------------------------------
void Game::keyReleased(int key){
	switch(key){
		case OF_KEY_LEFT:
		case 'a':
			left=false;
			break;
		case OF_KEY_RIGHT:
		case 'd':
			right=false;
			break;
		case OF_KEY_UP:
		case 'w':
			up=false;
			break;
		case OF_KEY_DOWN:
		case 's':
			down=false;
			break;
		case ' ':
			space=false;
			break;
	}
}

//--------------------------------------------------------------
void Game::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Game::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Game::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Game::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Game::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Game::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Game::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Game::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Game::dragEvent(ofDragInfo dragInfo){

}

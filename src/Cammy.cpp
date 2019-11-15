//
//  Cammy.cpp
//  3DMagic
//
//  Created by Ingo Raschka on 7/29/19.
//

#include "Cammy.h"

void Cammy::setup(){
	oldMouseX = ofGetMouseX();
	oldMouseY = ofGetMouseY();
	// EZCAM AND NODE INITIATION.
	ezcam.setDistance(160);
	tilt.setPosition(node.getPosition());
	tilt.setParent(node);
	ezcam.setParent(tilt);
	tilt.rotateDeg(-30, glm::vec3(1,0,0));
	// SO "NODE" ITSELF PANS - INSTEAD OF HAVING A SEPARATE "PAN" ofNODE. THIS IS BECAUSE THE CAMERA PAN AND THE DIRECTION SET ARE THE SAME- YOU DON'T WANT THE NODE TO NOT FACE THE RIGHT DIRECTION AND CALCULATE FROM THE PAN. TOO MANY AXIS.
}

void Cammy::update(){
	// DECLARE:
	int panRotation = 0;
	int tiltRotation = -30;
	int newMouseX = ofGetMouseX();
	int newMouseY = ofGetMouseY();
	// CAMMY PAN
	if(newMouseX < oldMouseX) {
		panRotation = -(oldMouseX - newMouseX);
	} else if(newMouseX > oldMouseX) {
		panRotation = newMouseX - oldMouseX;
	}
	if(newMouseX != oldMouseX){
		node.panDeg(panRotation);
	}
	// CAMMY TILT
	if(newMouseY < oldMouseY) {
		tiltRotation = (oldMouseY - newMouseY);
	} else if(newMouseY > oldMouseY) {
		tiltRotation = -(newMouseY - oldMouseY);
	}
	if(newMouseY != oldMouseY){
		// tilt.rotateDeg(tiltRotation/2, glm::vec3(1,0,0)); // (Quaternions...) ??
		// ofNode N GOES THE EXTRA MILE TO CHECK IF THE CAMERA ANGLE WILL OFFEND THE CLAMP.
		// IT IS A TEMPORARY NODE WHICH CHECKS IF THE ROTATION GOES BEYOND ITS ALLOWED 90º DEGREES.
		ofNode n;
		n.setOrientation(tilt.getOrientationEulerDeg());
		n.tiltDeg(tiltRotation);
		ofLog(OF_LOG_NOTICE,"nPitch" + ofToString(n.getPitchDeg()));
		
		int d = n.getPitchDeg();
		
		// TILT CLAMP (90º - 180º)
		if(d >= 90 && d <= 180){
			tilt.tiltDeg(tiltRotation/2);
		}else if(d < 90 && d >= 0){
			tilt.tiltDeg((90 - d) + 1);
		}else if(d >= -180 && d < 0){
			tilt.tiltDeg(-180 - d);
		}
		
		tilt.tiltDeg(tiltRotation);
	}
	
	ofLog(OF_LOG_NOTICE, "pitch: " + ofToString(tilt.getPitchDeg()));
	
	oldMouseX = ofGetMouseX();
	oldMouseY = ofGetMouseY();
	
	Fall(); ofLog(OF_LOG_NOTICE,ofToString(node.getY()));
	
	node.setPosition(node.getPosition() + direction);
	
	Ground();
	
}

void Cammy::draw(){
	ofSetColor(255,0,150,255);
	ofFill();
	ofDrawBox(node.getPosition(),camBodySize);
}

void Cammy::Jump(){
	direction.y = -jumpVelocity;
	onGround = false;
}

void Cammy::Fall(){
	if(!onGround){
		if(direction.y < terminalVelocity){
			direction.y += fallSpeed;
		}else if(direction.y >= terminalVelocity){
			direction.y = terminalVelocity;
		}
	}
}

void Cammy::Ground(){
	
	glm::vec3 p = node.getPosition();

	if(p.y > groundY){
		// GET BACK ON THE  EARTH.
		node.setPosition(p.x,groundY,p.z);
		direction.y = 0.0f;
		onGround = true;
	}
	/*
	if(p.y <= groundY && p.y >= groundY - 0.1f) {
		onGround = true;
	}else{
		onGround = false;
	}
	*/
}




























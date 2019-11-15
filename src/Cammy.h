//
//  Cammy.hpp
//  3DMagic
//
//  Created by Ingo Raschka on 7/29/19.
//

#ifndef Cammy_h
#define Cammy_h

#include <stdio.h>
#include "ofMain.h"

#endif /* Cammy_h */

// graphics library math

class Cammy
{
public:
	void setup();
	void update();
	void draw();
public:
	void Jump();
	void Fall();
	void Ground();
public:
	bool onGround = true;
	float speed = 7.0;
	glm::vec2 velocity = {0.0f,0.0f};
	float jumpVelocity = 100.0f;
	float terminalVelocity = 100.0f;
	float fallSpeed = 7.0f;
	float groundY = 0.0f;
	ofEasyCam ezcam;
	ofNode node;
	ofNode tilt;
	glm::vec2 direction = {0.0f,0.0f};
private:
	int oldMouseX, oldMouseY;
	int camBodySize = 10;
	
};

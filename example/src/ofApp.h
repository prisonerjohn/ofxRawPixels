#pragma once

#include "ofMain.h"
#include "ofxRawPixels.h"

class ofApp 
	: public ofBaseApp 
{
public:
	void setup() override;
	void exit() override;

	void update() override;
	void draw() override;

	void keyPressed(int key) override;

	ofImage charImageA;
	ofImage charImageB;

	ofxRawPixels::Serializer serializer;
};

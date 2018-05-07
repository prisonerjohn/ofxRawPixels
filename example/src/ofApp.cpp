#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(0);
	ofSetLogLevel(OF_LOG_VERBOSE);

	charImageA.load("mosaic.jpg");
}

//--------------------------------------------------------------
void ofApp::exit()
{

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	static const int kMargin = 10;
	static const int kSize = 512;

	charImageA.draw(kMargin, kMargin, kSize, kSize);
	if (charImageB.isAllocated())
	{
		charImageB.draw(kMargin * 2 + kSize, kMargin, kSize, kSize);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'C')
	{
		serializer.save(charImageA, "mosaic.rpx");

		ofPixels pixels;
		if (serializer.load(pixels, "mosaic.rpx"))
		{
			charImageB.setFromPixels(pixels);
		}
	}
}

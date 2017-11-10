#pragma once
#include "ofMain.h"

class Particle
{
public:
	Particle();
	~Particle() {};

	void update();
	void draw(vector<shared_ptr<Particle>> particles);

	ofVec2f get_location();
private:
	ofVec2f location;
	ofVec2f velocity;
	ofColor body_color;
};
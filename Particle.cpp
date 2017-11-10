#include "Particle.h"

Particle::Particle(){
	this->location = ofVec2f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2));
	this->velocity = ofVec2f(ofRandom(1.5, 3.0), 0);
	//this->body_color.setHsb(ofRandom(255), 255, 255);
	this->body_color = ofColor(0);
}

void Particle::update() {
	float x = this->location.x + this->velocity.x;
	float y = sin(x * this->velocity.x * 0.0025) * ofGetHeight() * 0.5;
	this->location = ofVec2f(x, y);

	if (this->location.x > ofGetWidth() / 2 + 3) {
		this->location.x = -ofGetWidth() / 2 - 3;
	}
}

void Particle::draw(vector<shared_ptr<Particle>> particles) {
	
	ofSetColor(this->body_color);
	ofDrawCircle(this->location, 3);

	float distance;
	for (int i = 0; i < particles.size(); i++) {
		distance = this->location.distance(particles[i]->get_location());
		if (distance > 0 && distance < 64) {
			ofSetColor(this->body_color, 255 - distance);
			ofDrawLine(this->location, particles[i]->get_location());
		}
	}
}

ofVec2f Particle::get_location() {
	return this->location;
}
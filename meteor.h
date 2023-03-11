#pragma once
#include "settings.h"
class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;


public:
	static std::string mFileNames[];
	Meteor() {
		int index = rand() % 8;
		texture.loadFromFile(mFileNames[index]);
		sprite.setTexture(texture);
		speedx = rand() % 5 - 2;
		speedy = rand() % 6 + 2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = -(rand() % (int)(WINDOW_HEIGHT - bounds.height) + bounds.height);
		sprite.setPosition(x, y);
	};
	void Update() {
		sprite.move(speedx, speedy);
	}

};

std::string Meteor::mFileNames[] = { "images\\meteorBrown_big1.png", "images\\meteorBrown_big2.png", "images\\meteorBrown_med1.png",
		"images\\meteorBrown_med2.png", "images\\meteorBrown_small1.png", "images\\meteorBrown_small2.png", "images\\meteorBrown_tiny1.png",
		"images\\meteorBrown_tiny2.png" };
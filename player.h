#pragma once
#include "settings.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setPosition(PLAYER_START_POS);
	}

	void update() {
		speedx = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			speedx = -PLAYER_SPEEDX;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			speedx = PLAYER_SPEEDX;
		sprite.move(speedx, 0.f);

		float playerx = sprite.getPosition().x;
		float playery = sprite.getPosition().y;
		if (playerx <= 0) sprite.setPosition(0.f, playery);
		if (playerx >= WINDOW_WIDTH - PLAYER_WIDTH)
			sprite.setPosition(WINDOW_WIDTH - PLAYER_WIDTH, playery);
	}
	sf::Sprite getSprite() { return sprite; }
	void setSprite(sf::Sprite fsprite) { sprite = fsprite; }

};
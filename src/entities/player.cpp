#include "player.hpp"


void Player::update(float dt){
	Vector2f velocity;

	if (Keyboard::isKeyPressed(Keyboard::Scan::W) || Keyboard::isKeyPressed(Keyboard::Scan::Up)) {
		velocity.y -= 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Scan::D) || Keyboard::isKeyPressed(Keyboard::Scan::Down)) {
		velocity.y += 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Scan::A) || Keyboard::isKeyPressed(Keyboard::Scan::Left)) {
		velocity.x -= 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Scan::D) || Keyboard::isKeyPressed(Keyboard::Scan::Right)) {
		velocity.x += 1;
	}

	velocity = (velocity == Vector2f(0, 0)) 
		? velocity 
		: Vector2f(velocity.normalized().x * speed, velocity.normalized().y * speed); // There is a better way (what way)
	position += velocity;

	// clamp the position to bounds
	// position = clamp<float>(0, 0, 0); // ill work on this tomorrow
}

Player::Player(float size, Vector2f position)
	: Entity(position, { size, size }) {}
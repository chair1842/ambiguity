#include "player.hpp"

void Player::update(float dt, vector<unique_ptr<Entity>>& entity_list) {
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
		: velocity.normalized() * static_cast<float>(speed) * dt; // The way has been found
	position += velocity;

	// clamp the position to bounds
	position = Vector2f(clamp<float>(position.x, 0, 480 - rect_size.x), clamp<float>(position.y, 0, 480 - rect_size.y)); // rect.y isnt nessecary, but anyways

}

Player::Player(float size, Vector2f pos) 
	: Entity(pos, { size, size }) {
	auto r = make_unique<RectangleShape>(Vector2f{ size, size });
	r->setFillColor(Color(128, 128, 255));
	drawable = move(r);
}
#include "bullet.hpp"

void Bullet::update(float dt, vector<unique_ptr<Entity>>& entity_list, vector<unique_ptr<Entity>>& to_spawn) {
	// move the bullet according to rotation and speed
	// then delete it if it goes out of bounds
	const float rad = rotation * (3.14159265f / 180.0f);
	Vector2f direction = Vector2f(cosf(rad), sinf(rad));
	position += direction * static_cast<float>(speed) * dt;

	// check for player, if hit, quit the game
	for (const auto& e : entity_list) {
		if (auto player = dynamic_cast<Player*>(e.get())) {
			if (checkCollision(*player)) {
				player->is_hit = true;
				to_delete = true;
			}
		}
	}

	// will throw an exeption. idk why
	if (position.x < -rect_size.x || position.x > 480 || position.y < -rect_size.y || position.y > 480) {
		to_delete = true;
	}
}

Bullet::Bullet(float angle, Vector2f pos)
	: CollisionEntity(pos, { 8, 8 }) {
	auto r = make_unique<RectangleShape>(Vector2f{ 8, 8 });
	r->setFillColor(Color(255, 255, 0));
	drawable = move(r);
	rotation = angle;
}
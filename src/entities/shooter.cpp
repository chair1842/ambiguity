#include "shooter.hpp"

Shooter::Shooter(Vector2f position, int cldwn)
	: Entity(position, { 32, 32 }) {
	cooldown = cldwn;
	auto r = make_unique<RectangleShape>(Vector2f{ 32, 32 });
	r->setFillColor(Color(255, 128, 128));
	drawable = move(r);
}

void Shooter::update(float dt, vector<unique_ptr<Entity>>& entity_list, vector<unique_ptr<Entity>>& to_spawn) {
	tsls += static_cast<int>(dt * 100); // convert to centiseconds
	// simple AI: shoot towards the player if cooldown is over
	if (tsls >= cooldown) {
		shoot(entity_list, to_spawn, to_delete);
		tsls = 0;
	}
}

void Shooter::shoot(vector<unique_ptr<Entity>>& entity_list, vector<unique_ptr<Entity>>& to_spawn, bool& to_delete) {
	// find the player entity
	Entity* player = nullptr;
	for (const auto& e : entity_list) {
		if (dynamic_cast<Player*>(e.get())) {
			player = e.get();
			break;
		}
	}
	if (!player) { to_delete = true; return; }// no player found
	// calculate angle towards player
	Vector2f direction = player->position - position;
	float angle = atan2f(direction.y, direction.x) * 180.0f / 3.14159265f; // Pie dont get it ;P
	// create a new bullet and add it to entity_list
	auto bullet = make_unique<Bullet>(angle, position + rect_size / 2.0f);
	to_spawn.push_back(move(bullet));
}
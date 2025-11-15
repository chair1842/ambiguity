#pragma once
#include "collision_entity.hpp"
#include <algorithm>
using namespace std;

class Player : public CollisionEntity {
public:
	const int speed = 500;
	bool is_hit = false;

	Player(float size, Vector2f position);
	void update(float dt, vector<unique_ptr<Entity>>& entity_list) override;
	void quit(RenderWindow& window);
};
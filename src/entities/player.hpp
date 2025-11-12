#pragma once
#include "entity.hpp"
#include <algorithm>
using namespace std;

class Player : public Entity {
public:
	const int speed = 500;

	Player(float size, Vector2f position);
	void update(float dt, const vector<unique_ptr<Entity>>& entity_list) override;
};
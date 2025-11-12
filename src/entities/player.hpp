#pragma once
#include "entity.hpp"
#include <algorithm>
using namespace std;

class Player : public Entity {
public:
	const int speed = 5;

	Player(float size, Vector2f position);
	void update(float dt) override;
};
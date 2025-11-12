#pragma once
#include "entity.hpp"
#include <algorithm>
using namespace std;

class Player : public Entity {
public:
	const int speed = 500;

	Player(float size, Vector2f position, Color color);
	void update(float dt) override;
};
#pragma once
#include "collision_entity.hpp"
#include <stdexcept>
#include <SFML/Audio.hpp>
#include <algorithm>
#include <print>

class Player : public CollisionEntity {
public:
	const int speed = 500;
	bool is_hit = false;
	int lives = 5;
	SoundBuffer hitsbuff;
	Sound hits;
	SoundBuffer painbuff;
	Sound pains;

	Player(float size, Vector2f position);
	void update(float dt, vector<unique_ptr<Entity>>& entity_list, vector<unique_ptr<Entity>>& to_spawn) override;
};
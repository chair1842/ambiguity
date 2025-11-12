#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
public:
	Vector2f position;
	Vector2f rect;

	Entity(Vector2f position = { 0, 0 }, Vector2f rect = { 0, 0 })
		: position(position), rect(rect) {}

	virtual void update(float dt) {}
};
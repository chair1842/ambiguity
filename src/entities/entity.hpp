#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
public:
	Vector2f position;
	Vector2f rect_size;

	Entity(Vector2f position = { 0, 0 }, Vector2f rect_size = { 0, 0 })
		: position(position), rect_size(rect_size)) {}

	virtual void update(float dt) {}
};
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
public:
	Vector2f position;
	Vector2f rect_size;
	Color color;
	RectangleShape shape;

	Entity(Vector2f position = { 0, 0 }, Vector2f rect_size = { 0, 0 }, Color color = Color::White)
		: position(position), rect_size(rect_size), color(color) {
		shape.setSize(rect_size);
		shape.setFillColor(color);
		shape.setPosition(position);
	}

	virtual void update(float dt) {}
	void sync_shape() { shape.setPosition(position); }
};
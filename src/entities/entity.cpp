#include "entity.hpp"

Entity::Entity(Vector2f position = { 0,0 }, Vector2f rect_size = { 0,0 })
    : position(position), rect_size(rect_size) { }

void Entity::draw(RenderTarget& target) {
    if (!drawable) return;

    if (auto t = dynamic_cast<Transformable*>(drawable.get())) {
        t->setPosition(position);
    }
    target.draw(*drawable);
}

void Entity::update(float dt, const vector<unique_ptr<Entity>>& entity_list) {}
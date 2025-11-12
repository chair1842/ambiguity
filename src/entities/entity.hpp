#include <SFML/Graphics.hpp>
#include <memory>
using namespace sf;
using namespace std;

class Entity {
public:
    Vector2f position;
    Vector2f rect_size;
    unique_ptr<Drawable> drawable; // points to actual shape or sprite

    Entity(Vector2f position = { 0,0 }, Vector2f rect_size = { 0,0 })
        : position(position), rect_size(rect_size)
    {
    }

    virtual void draw(RenderTarget& target) {
        if (!drawable) return;

        if (auto t = dynamic_cast<Transformable*>(drawable.get())) {
            t->setPosition(position);
        }
        target.draw(*drawable);
    }

    virtual void update(float dt, const vector<unique_ptr<Entity>>& entity_list) {}
};

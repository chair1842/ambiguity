#include <SFML/Graphics.hpp>
#include <memory>
using namespace sf;
using namespace std;

class Entity {
public:
    Vector2f position;
    Vector2f rect_size;
    unique_ptr<Drawable> drawable; // points to actual shape or sprite

    Entity(Vector2f position = { 0,0 }, Vector2f rect_size = { 0,0 });

    virtual void draw(RenderTarget& target);

    virtual void update(float dt, vector<unique_ptr<Entity>>& entity_list) {}
};

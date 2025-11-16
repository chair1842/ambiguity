#include <SFML/Graphics.hpp>
#include <vector>
#include "entities/player.hpp"
#include "entities/shooter.hpp"
using namespace sf;
using namespace std;

// Im using comments cuz im a noob :D
// (1, 0) is to the right, (0, 1) is to down

int main() {
    auto window = RenderWindow(VideoMode({480u, 480u}), "Avoidance");
    window.setFramerateLimit(60);

    vector<unique_ptr<Entity>> entity_list;
    entity_list.push_back(make_unique<Player>(32, Vector2f{ 224, 224 }));
	entity_list.push_back(make_unique<Shooter>(Vector2f{ 16, 16 }));
    //entity_list.push_back(make_unique<Shooter>(Vector2f{ 432, 16 }));
    //entity_list.push_back(make_unique<Shooter>(Vector2f{ 464, 464 }));
    //entity_list.push_back(make_unique<Shooter>(Vector2f{ 16, 464 }));

    auto last_time = chrono::high_resolution_clock::now();

    // Main game loop
    while (window.isOpen()) {
        // Poll for events
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
            {
                window.close();
            }
        }

        auto now = chrono::high_resolution_clock::now();
        float dt = duration_cast<chrono::duration<float>>(now - last_time).count();
        last_time = now;

        // vuvu :3
        // update loop for all entities
        for (auto& e : entity_list) {
            e->update(dt, entity_list);
        }

        // look for entities to delete
        entity_list.erase(
            remove_if(entity_list.begin(), entity_list.end(),
                [](const unique_ptr<Entity>& e) { return e->to_delete; }),
            entity_list.end()
        );

		// Clear and display
        window.clear();
		for (auto& e : entity_list) {
            e->draw(window); // wow, very nice
        }
        window.display();
    }

    return 0;
}

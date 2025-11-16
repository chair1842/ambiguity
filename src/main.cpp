#include <SFML/Graphics.hpp>
#include <vector>
#include <print>
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
	entity_list.push_back(make_unique<Shooter>(Vector2f{ 432, 16 }, 49));
	entity_list.push_back(make_unique<Shooter>(Vector2f{ 432, 432 }, 75));
	entity_list.push_back(make_unique<Shooter>(Vector2f{ 16, 432 }, 60));

	auto last_time = chrono::high_resolution_clock::now();

	// Sans
	Font sans;
	if (!sans.openFromFile("StackSansText.tff")) {
		println("Couldn't load StackSans!");
		println("Good luck next time myboy");
		return -1;
	}

	// pause variables
	bool paused = false;

	// pause text
	Text pause_text(sans, "Paused", 60);
	pause_text.setFillColor(Color::White);
	pause_text.setPosition({ 0, (480 / 2) - 30 });

	// Main game loop
	while (window.isOpen()) {
		// Poll for events
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>()) { window.close(); }
			// Pause
			if (const auto* key = event->getIf<Event::KeyPressed>()) {
				if (key->scancode == Keyboard::Scan::Escape) {
					paused = !paused;
				}
			}
			if (event->is<Event::FocusLost>()) { paused = true; }
		}

		auto now = chrono::high_resolution_clock::now();
		float dt = duration_cast<chrono::duration<float>>(now - last_time).count();
		last_time = now;

		vector<unique_ptr<Entity>> to_spawn;

		// vuvu :3
		// pause functionality ^v^
		if (!paused) {
			// update loop for all entities
			for (auto& e : entity_list) {
				e->update(dt, entity_list, to_spawn);
			}

			// spawn buffer
			for (auto& e : to_spawn) {
				entity_list.push_back(std::move(e));
			}
			to_spawn.clear(); // clear the spawn buffer

			// look for entities to delete
			entity_list.erase(
				// remove if from all of the entities, if to_delete is true
				remove_if(entity_list.begin(), entity_list.end(),
					[](const unique_ptr<Entity>& e) { return e->to_delete; }),
				entity_list.end()
			);
		}

		// Clear and display
		window.clear();
		for (auto& e : entity_list) {
			e->draw(window); // wow, very nice
		}
		if (paused) {
			window.draw(pause_text);
		}
		window.display();
	}

	return 0;
}

// im so bad at this game fr 3x
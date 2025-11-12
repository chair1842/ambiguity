#include <SFML/Graphics.hpp>
#include "entities/player.hpp"
using namespace sf;
using namespace std;

// Im using comments cuz im a noob :D
// (1, 0) is to the right, (0, 1) is to down

int main() {
    auto window = RenderWindow(VideoMode({480u, 480u}), "Avoidance");
    window.setFramerateLimit(60);

    Player player(32, {0,0});

    RectangleShape rect;
    rect.setSize(player.rect);

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

        player.update(0);
        rect.setPosition(player.position);

		// Clear and display
        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}

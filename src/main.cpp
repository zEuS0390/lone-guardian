#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <queue>
#include "bullet.h"
#include "player.h"

class game {
    public:
	game ();
	void run();
    private:
        sf::RenderWindow    mWindow;
        void                processEvents ();
        void                update (sf::Time);
        void                render ();
    private:
        Player player;
        std::list<Bullet*> bullets;
};

game::game ():
mWindow(sf::VideoMode(800, 600), "2D Top Down Shooter"),
player() {
	player.setPosition(400.0f, 300.0f);
}

// Game loop
void game::run () {
	sf::Clock clock;

	const sf::Time TimePerFrame = sf::seconds(1.0f/60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while(timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		render();
	}
}

// Event handling method
void game::processEvents () {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					mWindow.close();
				player.handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				player.handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					Bullet* bullet = new Bullet(mWindow, player.getPosition(), sf::Mouse());
					bullets.push_back(bullet);
				}
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

// Update method
void game::update (sf::Time deltaTime) {

	player.update(mWindow, sf::Mouse(), deltaTime);

	for (auto bullet: bullets)
		bullet->update(deltaTime);

	auto i = bullets.begin();
	while (i != bullets.end()) {
		Bullet* bullet = *i;

		if (bullet->getPosition().x > mWindow.getSize().x ||
			bullet->getPosition().x < 0 ||
			bullet->getPosition().y > mWindow.getSize().y ||
			bullet->getPosition().y < 0) {

			delete bullet; // Deallocate memory
			i = bullets.erase(i); // Erase the element and get the next iterator

			std::cout << "Object Erased!" << std::endl;
		} else {
			++i; // Only increment if not erasing
		}

	}

}

// Render method
void game::render () {
	mWindow.clear();

	for (auto bullet: bullets)
		mWindow.draw(*bullet);

	mWindow.draw(player);
	mWindow.display();
}

// Main function
int main () {
	game Game;
	Game.run();
	return 0;
}

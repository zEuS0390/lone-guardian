#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"
#include "player.h"

class game {
    public:
             game ();
        void run (void);
    private:
        sf::RenderWindow    mWindow;
        void                processEvents (void);
        void                update (sf::Time);
        void                render (void);
    private:
        Player player;
        Bullet bullet;
};

game::game ():
mWindow(sf::VideoMode(800, 600), "2D Top Down Shooter"),
player() {
    player.setPosition(400.0f, 300.0f);
}

// Game loop
void game::run (void) {
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
    return;
}

// Event handling method
void game::processEvents (void) {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    mWindow.close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    bullet.setPosition(player.getPosition().x, player.getPosition().y);
                    bullet.shoot(mWindow, player.getPosition(), sf::Mouse());
                }
                player.handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                player.handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
    return;
}

// Update method
void game::update (sf::Time deltaTime) {
    player.update(mWindow, sf::Mouse(), deltaTime);
    bullet.update(deltaTime);
    return;
}

// Render method
void game::render (void) {
    mWindow.clear();
    mWindow.draw(bullet);
    mWindow.draw(player);
    mWindow.display();
    return;
}

// MAIN FUNCTION
int main (void) {
    game Game;
    Game.run();
    return 0;
}

#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include <SFML/Graphics.hpp>

class Player: public Sprite {
    public:
        Player              (void);
        void update         (sf::RenderWindow&, sf::Mouse, sf::Time);
        void handlePlayerInput  (sf::Keyboard::Key, bool);
    private:
        float movementSpeed;
        bool    isMovingUp, isMovingDown,
                isMovingLeft, isMovingRight;
        sf::Vector2f movement;
    private:
        void PointToMouse       (sf::RenderWindow&, sf::Mouse);
        void playerMove         (sf::Time);
};

#endif // PLAYER_H

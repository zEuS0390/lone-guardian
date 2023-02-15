#ifndef BULLET_H
#define BULLET_H

#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <string>

class Bullet: public Sprite {
    public:
        sf::Vector2f aimDir;
        sf::Vector2f aimDirNorm;
    public:
                Bullet      (sf::RenderWindow&, const sf::Vector2f&, sf::Mouse);
        void    update      (sf::Time);
        void    shoot       (sf::RenderWindow&, const sf::Vector2f&, sf::Mouse);
        void    moveBullet        (sf::Time);
};

#endif

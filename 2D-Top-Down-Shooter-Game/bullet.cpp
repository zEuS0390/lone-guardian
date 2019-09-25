#include "bullet.h"
#include "sprite.h"
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

Bullet::Bullet(sf::RenderWindow& window, const sf::Vector2f& position, sf::Mouse mouse, const std::string fileLocation):
Sprite(fileLocation){
    setPosition(position.x, position.y);
    shoot(window, position, mouse);
}

void Bullet::moveBullet (sf::Time deltaTime) {
    move(aimDirNorm*deltaTime.asSeconds()*500.0f);
    return;
}

void Bullet::update(sf::Time deltaTime) {
    moveBullet(deltaTime);
    return;
}

void Bullet::shoot (sf::RenderWindow& window, const sf::Vector2f& playerPos, sf::Mouse mouse) {
    sf::Vector2f mousePos(mouse.getPosition(window).x, mouse.getPosition(window).y);
    aimDir = mousePos - playerPos;
    double angle = atan2(aimDir.y, aimDir.x);
    aimDirNorm.x = aimDir.x / aimDir.x*cos(angle);
    aimDirNorm.y = aimDir.y / aimDir.y*sin(angle);
    std::cout << "Aim Position: [" << aimDir.x << ", " << aimDir.y << "]" << std::endl;
    return;
}

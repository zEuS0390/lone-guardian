#include "bullet.h"
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

Bullet::Bullet():
Sprite("img/bullet.png"){
}

void Bullet::moveBullet (sf::Time deltaTime) {
    move(aimDirNorm*deltaTime.asSeconds()*500.0f);
    return;
}

void Bullet::update(sf::Time deltaTime) {
    moveBullet(deltaTime);
    return;
}

void Bullet::shoot (sf::RenderWindow &window, sf::Vector2f playerPos, sf::Mouse mouse) {
    sf::Vector2f mousePos(mouse.getPosition(window).x, mouse.getPosition(window).y);
    aimDir = mousePos - playerPos;
    double angle = atan2(aimDir.y, aimDir.x);
    aimDirNorm.x = aimDir.x / aimDir.x*cos(angle);
    aimDirNorm.y = aimDir.y / aimDir.y*sin(angle);
    std::cout << "Aim Position: [" << aimDir.x << ", " << aimDir.y << "]" << std::endl;
    return;
}

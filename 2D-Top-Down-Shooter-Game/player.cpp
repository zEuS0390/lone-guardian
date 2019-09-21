#include "player.h"
#include "sprite.h"
#include <string>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

Player::Player(void):
    Sprite          ("img/player.png"),
    isMovingUp      (false),            isMovingDown    (false),
    isMovingLeft    (false),            isMovingRight   (false),
    movement        (0.0f, 0.0f),       movementSpeed   (500.0f){
}

void Player::PointToMouse (sf::RenderWindow &window, sf::Mouse mouse) {
    double y = mouse.getPosition(window).y - getPosition().y;
    double x = mouse.getPosition(window).x - getPosition().x;
    float angle = (float)atan2(y, x);
    setRotation(angle * (180/3.14152) + 90);
    return;
}

void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        isMovingRight = isPressed;
    //else if (key == sf::Keyboard::Space && isPressed == true)
    //    std::cout << "Spacebar pressed..." << std::endl;
    return;
}

void Player::playerMove (sf::Time deltaTime) {
    movement.x = 0.0f;
    movement.y = 0.0f;
    if (isMovingUp)
        movement.y -= movementSpeed;
    if (isMovingDown)
        movement.y = movementSpeed;
    if (isMovingLeft)
        movement.x -= movementSpeed;
    if (isMovingRight)
        movement.x = movementSpeed;
    move(movement * deltaTime.asSeconds());
    return;
}

void Player::update (sf::RenderWindow &window, sf::Mouse mouse, sf::Time deltaTime) {
    PointToMouse(window, mouse);
    playerMove(deltaTime);
    return;
}

#include "sprite.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

Sprite::Sprite(const std::string fileLocation)
{
    loadFile(image, fileLocation);
    image.createMaskFromColor(sf::Color(255, 255 , 255), 0);
    texture.loadFromImage(image);
    setTexture(texture);
    setOrigin(texture.getSize().x/2.0f, texture.getSize().y/2.0f);
}

void Sprite::loadFile(sf::Image &img, const std::string fileLocation) {
    if (!img.loadFromFile(fileLocation))
        std::cout << "Error loading image!" << std::endl;
    return;
}

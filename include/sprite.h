#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

class Sprite: public sf::Sprite {
    private:
        void            loadFile(sf::Image&, const std::string);
    public:
        sf::Image           image;
        sf::Texture         texture;
    public:
        Sprite          (const std::string);
};

#endif

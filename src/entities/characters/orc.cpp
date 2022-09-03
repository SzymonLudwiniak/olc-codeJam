//
// Created by szymon on 03.09.22.
//

#include "../../../include/entities/characters/orc.hpp"
#include "../../../include/defines.hpp"

#include <math.h>


Orc::Orc(bool good, sf::Vector2f position) : Unit(position) {
    sprite.setFillColor(sf::Color::Black);
}

void Orc::move(float deltaTime) {
    float x, y;
    if (followedEntity != nullptr) {
        x = rand()%(TILEWIDTH*SCREENWIDTH);
        y = rand()%(TILEHEIGHT*SCREENHEIGHT);
    }
    else {
        x = destination.x - position.x;
        y = destination.y - position.y;
    }

    if(x*x + y*y < 100) return;

    float theta = atan2(y, x);


    Entity::move(sf::Vector2f(deltaTime * speed * cos(theta), deltaTime*speed* -sin(theta)));
}

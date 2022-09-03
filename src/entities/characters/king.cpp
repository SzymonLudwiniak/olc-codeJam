//
// Created by szymon on 29.08.22.
//

#include "../../../include/entities/characters/king.hpp"

#include <math.h>

King::King(bool good, sf::Vector2f position)
: Unit(position) {
    sprite.setFillColor(sf::Color::Black);
}

void King::move(float deltaTime) {

    float x, y;
    if (followedEntity != nullptr) {
        x = followedEntity->getPosition().x - position.x;
        y = followedEntity->getPosition().y - position.y;
    }
    else {
        x = destination.x - position.x;
        y = destination.y - position.y;
    }

    if(x*x + y*y < 100) return;

    float theta = atan2(y, x);


    Entity::move(sf::Vector2f(deltaTime * speed * (cos(theta) - sin(theta)),
                              deltaTime * speed * (sin(theta) + cos(theta))));
}

//void King::draw(sf::RenderTarget & target, sf::RenderStates state) const {
//    target.draw(sprite, state);
//}
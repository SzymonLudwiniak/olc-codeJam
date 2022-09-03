//
// Created by szymon on 28.08.22.
//

#include "../../include/entities/entity.hpp"

#include <math.h>

Entity::Entity(sf::Vector2f position, float speed)
: position(position), speed(speed){

    direction = 0;
    size = sf::Vector2i(16, 16);
    sprite.setSize(sf::Vector2f(16.f, 16.f));
}

void Entity::setPosition(const sf::Vector2f &vec) {
    position = vec;
    sprite.setPosition(vec);
}

sf::Vector2f Entity::getPosition() const{
    return position;
}

void Entity::setTexture(sf::Texture *texture) {
    sprite.setTexture(texture);
}

void Entity::move(const sf::Vector2f & vec) {
    position += vec;
    sprite.setPosition(position);
}

void Entity::move(float deltaTime) {
    position += sf::Vector2f(speed * cos(direction) * deltaTime,
                             speed * -sin(direction) * deltaTime);
    sprite.setPosition(position);
}

void Entity::rotate(float angle, float deltaTime) {
    direction += angle * deltaTime;
}

void Entity::setDirection(float direction) {
    this->direction = direction;
}


void Entity::draw(sf::RenderTarget & target, sf::RenderStates state) const {
    target.draw(sprite, state);
}
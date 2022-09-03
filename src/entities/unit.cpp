//
// Created by szymon on 30.08.22.
//

#include "../../include/entities/unit.hpp"

Unit::Unit(sf::Vector2f position, float health, int strenght, float range, bool good)
: Entity(position, 64), range(range), health(health), strenght(strenght), good(good)  {
    followedEntity = nullptr;

}

void Unit::attack() {

}

void Unit::setDestination(const sf::Vector2f &destination) {
    this->destination = destination;
}

void Unit::setDestination(Entity * destination) {
    this->followedEntity = destination;
}

void Unit::move(float deltaTime) {

}


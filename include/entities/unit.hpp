//
// Created by szymon on 30.08.22.
//

#ifndef CODEJAM_UNIT_HPP
#define CODEJAM_UNIT_HPP

#include "entity.hpp"

class Unit : public Entity {

protected:
    sf::Vector2f destination;
    Entity * followedEntity;

    float range;

    float health;
    int strenght;

    bool good;

    virtual void attack();
public:

    Unit(sf::Vector2f position, float health = 0.f, int strenght = 0, float range = 0.f, bool good = true);

    virtual void setDestination(const sf::Vector2f & destination);
    virtual void setDestination(Entity * destination);
    virtual void move(float deltaTime);
};


#endif //CODEJAM_UNIT_HPP

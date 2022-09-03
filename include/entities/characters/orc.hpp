//
// Created by szymon on 03.09.22.
//

#ifndef CODEJAM_ORC_HPP
#define CODEJAM_ORC_HPP

#include "../unit.hpp"

class Orc : public Unit {

public:
    Orc(bool good, sf::Vector2f position = sf::Vector2f(0.f, 0.f));

    virtual void move(float deltaTime);
};


#endif //CODEJAM_ORC_HPP

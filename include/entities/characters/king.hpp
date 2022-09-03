//
// Created by szymon on 29.08.22.
//

#ifndef CODEJAM_KING_HPP
#define CODEJAM_KING_HPP

#include "../unit.hpp"

class King : public Unit {


public:
    King(bool good, sf::Vector2f position = sf::Vector2f(0.f, 0.f));

    virtual void move(float deltaTime);

    virtual void draw(sf::RenderTarget & target, sf::RenderStates state) const;
};


#endif //CODEJAM_KING_HPP

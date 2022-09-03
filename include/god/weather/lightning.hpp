//
// Created by szymon on 02.09.22.
//

#ifndef CODEJAM_LIGHTNING_HPP
#define CODEJAM_LIGHTNING_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Lightning : public sf::Drawable{
    std::vector<sf::Vertex> vertices;
    bool visible;

    sf::Vector2f targetPlace;
    void generateSegment();
public:
    void rise();
    Lightning(const sf::Vector2f & place);


    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};


#endif //CODEJAM_LIGHTNING_HPP

//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_ENTITY_HPP
#define CODEJAM_ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable {

protected:
    sf::RectangleShape sprite;

    sf::Vector2f position;
    sf::Vector2i size;

    float speed;
    float direction;

public:
    explicit Entity(sf::Vector2f position = sf::Vector2f(0.f, 0.f), float speed = 640.f);

    void setTexture(sf::Texture* texture);

    void setPosition(const sf::Vector2f & vec);
    sf::Vector2f getPosition() const;

    void move(const sf::Vector2f & vec);
    virtual void move(float deltaTime);

    void rotate(float angle, float deltaTime);
    void setDirection(float direction);

    virtual void draw(sf::RenderTarget & target, sf::RenderStates state) const;
};


#endif //CODEJAM_ENTITY_HPP

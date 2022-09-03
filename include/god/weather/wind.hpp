//
// Created by szymon on 31.08.22.
//

#ifndef CODEJAM_WIND_HPP
#define CODEJAM_WIND_HPP

#include "../../entities/entity.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Wind : public sf::Drawable {
    friend class God;

    static sf::Texture * texture;
    bool works;

    float lifeTime;
    float strength;

    float angle;

    sf::Vector2f start, end;
    sf::Vector2f vector;
    sf::Vertex vertices[4];

public:
    static void loadWindTexture();

    Wind(sf::Vector2f start, sf::Vector2f end);

    void adjustTo(sf::Vector2f position);
    void setWorking(bool works);
    void setLifeTime(float lifeTime);
    void setStrength(float strength);

    sf::Vertex * getWindBounds();
    bool isInBounds(Entity * entity);

    void blow(std::vector<Entity *> & entities, float deltaTime);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //CODEJAM_WIND_HPP

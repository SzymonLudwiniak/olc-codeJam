//
// Created by szymon on 31.08.22.
//

#include "../../../include/god/weather/wind.hpp"

#include <math.h>
#include <iostream>

sf::Texture* Wind::texture = new sf::Texture();

void Wind::loadWindTexture() {

    texture->loadFromFile("./textures/blueArrow.png");
}

Wind::Wind(sf::Vector2f start, sf::Vector2f end) {

    angle = 0.f;
    strength = 400.f;
    this->start = start;
    this->end = end;

    vector = sf::Vector2f (end.x - start.x, end.y - start.y);

    vertices[0].position = sf::Vector2f(start.x, start.y - 16);
    vertices[1].position = sf::Vector2f(end.x, end.y - 16);
    vertices[2].position = sf::Vector2f(end.x, end.y + 16);
    vertices[3].position = sf::Vector2f(start.x, start.y + 16);

    vertices[0].texCoords = sf::Vector2f(0.f, 0.f);
    vertices[1].texCoords = sf::Vector2f(64.f, 0.f);
    vertices[2].texCoords = sf::Vector2f(64.f, 32.f);
    vertices[3].texCoords = sf::Vector2f(0.f, 32.f);
}

void Wind::adjustTo(sf::Vector2f position) {

    float newAngle;

    newAngle = atan2(position.y - start.y, position.x - start.x);
    newAngle *= 180/M_PI;

    float thetaDiff = newAngle - angle;

    //i hate math i hate math

    float oldLength = sqrt(vector.x*vector.x + vector.y*vector.y);
    float newLength = sqrt((position.x - start.x)*(position.x - start.x)+
                           (position.y - start.y)*(position.y - start.y));

    float lengthRatio = newLength/oldLength;

    sf::Transform rotation;
    rotation.rotate(thetaDiff, start);

    sf::Vector2f offset = vector * lengthRatio;

    vertices[1].position = vertices[0].position + offset;
    vertices[2].position = vertices[3].position + offset;

    vertices[0].position = rotation.transformPoint(vertices[0].position);
    vertices[1].position = rotation.transformPoint(vertices[1].position);
    vertices[2].position = rotation.transformPoint(vertices[2].position);
    vertices[3].position = rotation.transformPoint(vertices[3].position);


    end = position;
    angle = newAngle;
    vector = sf::Vector2f (end.x - start.x, end.y - start.y);

}

void Wind::setWorking(bool works) {
    this->works = works;
}

void Wind::setLifeTime(float lifeTime) {
    this->lifeTime = lifeTime;
}

void Wind::setStrength(float strength) {
    this->strength = strength;
}

sf::Vertex* Wind::getWindBounds() {
    return vertices;
}

bool Wind::isInBounds(Entity * entity) {
    sf::Vector2f entityPos = entity->getPosition();

    sf::Vector2f pos1 = vertices[0].position;
    sf::Vector2f pos2 = vertices[1].position;

    int index = 1;
    for(int i = 0; i < 4; i++) {
        float D = (pos2.x - pos1.x) * (entityPos.y - pos1.y) -
                  (entityPos.x - pos1.x) * (pos2.y - pos1.y);
        if (D < 0) return false;

        pos1 = pos2;
        pos2 = vertices[(++index)%4].position;
    }
    return true;
}

void Wind::blow(std::vector<Entity *> & entities, float deltaTime) {
    sf::Vector2f versor = 1.f/sqrt(vector.x*vector.x + vector.y*vector.y)*vector;
    for(auto & entity : entities) {
        if(isInBounds(entity)) {
            entity->move(strength*versor*deltaTime);
        }
    }
}

void Wind::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    states.texture = texture;
    target.draw(vertices, 4, sf::Quads, states);
}
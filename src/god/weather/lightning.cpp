//
// Created by szymon on 02.09.22.
//

#include "../../../include/god/weather/lightning.hpp"
#include <random>

static std::random_device __randomDevice;
static std::mt19937 __randomGen(__randomDevice());
static std::normal_distribution<float> distribution(0.f, 60.f);


Lightning::Lightning(const sf::Vector2f & place) {
    visible = true;
    targetPlace = place;
    vertices.push_back(sf::Vertex(place));

    float theta = distribution(__randomGen);
    sf::Transform transformation;
    transformation.rotate(theta, vertices.back().position);

    sf::Vertex vertex;
    vertex.position = transformation.transformPoint(place.x, vertices.back().position.y - 30);

    vertices.push_back(vertex);
}

void Lightning::rise() {
    if(vertices.size() > 200) {
        visible = false;
        return;
    }
    generateSegment();
}

void Lightning::generateSegment() {

    float theta = distribution(__randomGen);
    sf::Transform transformation;
    transformation.rotate(theta, vertices.back().position);

    sf::Vertex vertex;
    vertex.position = transformation.transformPoint(vertices.back().position.x, vertices.back().position.y - 30);

    vertices.push_back(vertices.back());
    vertices.push_back(vertex);
}


void Lightning::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    if(!visible)
        return;

    target.draw(&vertices[0], vertices.size(), sf::Lines, states);
}




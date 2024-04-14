#include "Cell.h"
#include <iostream>

Cell::Cell(int i, int j, int w) {
    this->alive = false;
    this->shape.setFillColor(sf::Color(46, 47, 48));
    this->shape.setOutlineColor(sf::Color(196, 196, 196, 0));
    this->shape.setOutlineThickness(1);
    this->shape.setSize(sf::Vector2f(10, 10));
    this->x = i;
    this->y = j;
    this->cellSize = w;
}

Cell::~Cell() { }

bool Cell::isAlive() {
    return this->alive;
}

int Cell::getX() { return this->x; }

int Cell::getY() { return this->y; }

void Cell::draw(sf::RenderWindow& window) {
    int xCoord = this->x * this->cellSize;
    int yCoord = this->y * this->cellSize;
    this->shape.setPosition(sf::Vector2f(xCoord, yCoord));
    window.draw(this->shape);
}

void Cell::setPosition(sf::Vector2f pos) {
    this->shape.setPosition(pos);
}

void Cell::kill() {
    this->alive = false;
    this->shape.setFillColor(sf::Color(46, 47, 48));
}

void Cell::born() {
    this->alive = true;
    this->shape.setFillColor(sf::Color(6, 13, 148));
}

void Cell::update(sf::RenderWindow& window, sf::Clock& clockActivating, sf::Time& elapsedActivated) {
    if (elapsedActivated.asSeconds() >= 0.2) {
        clockActivating.restart();
        if (this->alive) {
            this->alive = false;
            this->kill();
        }
        else {
            this->alive = true;
            this->born();
        }
    }
}

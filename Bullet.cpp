//
// Created by Salamon on 5/4/2022.
//

#include "Bullet.h"

Bullet::Bullet(sf::Texture *bulletTex) {
    this->bulletShape.setTexture(*bulletTex);
    this->bulletShape.setTextureRect(sf::IntRect(500, 0, 20, 100));
    this->bulletShape.setScale(sf::Vector2f(0.1f, 0.1f));

}
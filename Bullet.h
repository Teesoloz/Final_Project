//
// Created by Salamon on 5/4/2022.
//

#ifndef FINAL_PROJECT_BULLET_H
#define FINAL_PROJECT_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    sf::Sprite bulletShape;

    Bullet(sf::Texture *bulletTex);

    ~Bullet() {};

};


#endif //FINAL_PROJECT_BULLET_H

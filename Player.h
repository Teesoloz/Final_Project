//
// Created by Salamon on 5/4/2022.
//

#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <vector>


class Player {
public:
    sf::Texture *playerTex;
    sf::Sprite body;

    std::vector<Bullet> bullets; //An array of BULLETS (from Bullet class)


    Player(sf::Texture *playerTex);
    void move(sf::RenderWindow &window);

    ~Player() {};

    void centralizePlayer(sf::RenderWindow &window);


};


#endif //FINAL_PROJECT_PLAYER_H

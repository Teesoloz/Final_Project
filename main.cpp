//
// Created by Salamon on 4/30/2022.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>     /* srand, rand */
#include "Player.h"
#include "Bullet.h"



int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Invader Shooter (River Raid)");
    window.setFramerateLimit(60);
    /* initialize random seed: */
    srand(time(nullptr)); //Random number generator
    int bulletTimer = 0;
    int enemyGenerator = 0;
    int score = 0;

    // Game components

    //create one Bullet Texture



    //create player
    sf::Texture playerTex;
    if (!playerTex.loadFromFile("../Textures/player.png"))
        throw ("error loading Player texture");
    Player player(&playerTex);
    player.centralizePlayer(window);

    //create bullet
    sf::Texture bulletTex;

    if(!bulletTex.loadFromFile("../Textures/bullet.png")){
        throw ("error loading Bullet texture");
    }




    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.move(window); //move player relative to the window

        //DRAW
        window.clear(sf::Color::Black);
        for (auto i = 0; i < player.bullets.size(); i++) {
            window.draw(player.bullets[i].bulletShape);
        }

        window.draw(player.body);

        window.display();

    }

    return 0;
}


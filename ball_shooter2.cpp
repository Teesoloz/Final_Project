//
// Created by Salamon on 4/30/2022.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Invader Shooter (River Raid)");
    window.setFramerateLimit(60);
    /* initialize random seed: */
    srand(time(nullptr)); //Random number generator
    int bulletTimer = 0;
    int enemyGenerator = 0;
    int score = 0;

    // Game components

    //create one bullet

    sf::Texture bulletTex;
    sf::Sprite bullet;
    if (!bulletTex.loadFromFile("bullet.jpg"))
        throw ("error loading bullet texture");
    bullet.setTexture(bulletTex);
    bullet.setTextureRect(sf::IntRect(500, 0, 20, 100));
    bullet.setScale(sf::Vector2f(0.1f, 0.1f));


    //create one enemy
    sf::Texture enemyTex;
    sf::Sprite enemy;
    if (!enemyTex.loadFromFile("../enemy.png"))
        throw ("error loading player texture");
    enemy.setTexture(enemyTex);
    enemy.setScale(sf::Vector2f(0.1f, 0.1f));


    sf::Texture playerTex;
    sf::Sprite player;
    if (!playerTex.loadFromFile("../ship.png"))
        throw ("error loading player texture");
    player.setTexture(playerTex);

    player.setPosition(sf::Vector2f(window.getSize().x / 2 + player.getGlobalBounds().width / 2,
                                    window.getSize().y - player.getGlobalBounds().height / 2));

    //Player center (serves as the origin for bullets while shooting at enemy)
    player.setScale(sf::Vector2f(0.05f, 0.05f));


    std::vector<sf::Sprite> enemies; //An Array of enemies
    std::vector<sf::Sprite> bullets; //An Array of bullets

    enemies.push_back(sf::Sprite(enemy));
    bullets.push_back(sf::Sprite(bullet)); //Add a bullet to the array of BULLETS



    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //BULLETS
        if (bulletTimer < 20) //Controls the amount of bullets per time (so as not to waste bullets)
            bulletTimer++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletTimer >= 20) {
            bullet.setPosition(player.getPosition());
            bullets.push_back(sf::Sprite(bullet));
            bulletTimer = 0;
        }


        //Make bullets disappear when they meet target or hit a dead end
        for (auto i = 0; i < bullets.size(); i++) {

            bullets[i].move(0.0f, -10.0f);
            if (bullets[i].getPosition().y <= 0)
                bullets.erase(bullets.begin() + i);
        }


        //ENEMIES
        if (enemyGenerator < 50) //Controls the amount of bullets per time (so as not to waste bullets)
            enemyGenerator++;
        if (enemyGenerator >= 50) {
            enemy.setPosition(window.getSize().x - enemy.getGlobalBounds().width,
                              rand() % window.getSize().y - enemy.getGlobalBounds().height * 4);
            if (enemy.getPosition().y >= 0) { //We want all the enemies to be within the window
                enemies.push_back(sf::Sprite(enemy));
                enemyGenerator = 0;
            }

        }

        //Make enemies move across the River
        for (auto i = 0; i < enemies.size(); i++) {
            enemies[i].move(-5.0f, 0.0f);
            if (enemies[i].getPosition().x <= -enemy.getGlobalBounds().width)
                enemies.erase(enemies.begin() + i);
        }

        //COLLISION between bullets and enemies
        for (auto i = 0; i < bullets.size(); i++) {
            for (auto j = 0; j < enemies.size(); j++) {
                if (bullets[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                    bullets.erase(bullets.begin() + i);
                    enemies.erase(enemies.begin() + j);
                    score += 1;
                    std::cout << score << std::endl;
                    break;

                }
            }
        }

        //Move player left and right

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {

            player.move(2.0f, 0.0f);
            //bullet.move(2.0f, 0.0f);
            if (player.getPosition().x + player.getGlobalBounds().width >= window.getSize().x)
                player.setPosition(window.getSize().x - player.getGlobalBounds().width, player.getPosition().y);


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {


            player.move(-2.0f, 0.0f);
            //bullet.move(2.0f, 0.0f);
            if (player.getPosition().x <= 0)
                player.move(-player.getPosition().x, 0.0f);
        }


        //DRAW
        window.clear(sf::Color::Black);


        for (size_t i = 0; i < enemies.size(); i++) {
            window.draw(enemies[i]);
        }

        for (auto i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i]);
        }
        window.draw(player);

        window.display();

    }

    return 0;
}


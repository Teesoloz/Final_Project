//
// Created by Salamon on 5/4/2022.
//

#include "Player.h"

Player::Player(sf::Texture *playerTex) {
    this->playerTex = playerTex;
    this->body.setTexture(*playerTex);
    this->body.setScale(0.05f, 0.05f);
};

//Set player position relative to the window
void Player::centralizePlayer(sf::RenderWindow &window) {
    this->body.setPosition(sf::Vector2f(window.getSize().x / 2 + this->body.getGlobalBounds().width / 2,
                                        window.getSize().y - this->body.getGlobalBounds().height));
}


void Player::move(sf::RenderWindow &window) {
    //Move player left and right

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {

        this->body.move(2.0f, 0.0f);
        //bullet.move(2.0f, 0.0f);
        if (this->body.getPosition().x + this->body.getGlobalBounds().width >= window.getSize().x)
            this->body.setPosition(window.getSize().x - this->body.getGlobalBounds().width, this->body.getPosition().y);


    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {


        this->body.move(-2.0f, 0.0f);
        //bullet.move(2.0f, 0.0f);
        if (this->body.getPosition().x <= 0)
            this->body.move(-this->body.getPosition().x, 0.0f);
    }
}
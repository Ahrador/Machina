#include <iostream>
#include <SFML/Window.hpp> // include cijeli Window module
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include "C:/Users/Student/Desktop/SFML-2.5.1/include/SFML/Window/Window.hpp" // include klase
using namespace std;

// Predavanje 8 - Uvod u SFML

// za koristenje vanjskih libraryja:
// 1. include header
// 2. include code (lib + ako treba dll)

// basic		osnovni library
// -d			debug verzija
// -s           staticka verzija
// -s-d         staticka debug verzija

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::InputSoundFile bla; 

    sf::Vector2f mario_position;
    mario_position.x = 390;
    mario_position.y = 330;

    sf::Texture mario_sheet;
    mario_sheet.loadFromFile("C:/Users/Alen/Desktop/Coding/mario.png");

    sf::Sprite mario_sprite;
    mario_sprite.setTexture(mario_sheet);

    //mario_sprite.setOrigin(203, 194);
    //sf::IntRect parametri;
    //parametri.left = 203;
    //parametri.top = 194;
    // ..
    //mario_sprite.setTextureRect(parametri);
    mario_sprite.setTextureRect(
        { 203, 194, 27, 32 }
    );

    const int SCALING_FACTOR = 6;
    mario_sprite.setScale(SCALING_FACTOR, SCALING_FACTOR);
    // position: 5, 75
    // 46, 75
    // size: 22 x 30
    std::vector<sf::IntRect>  frejmovi = {
        { 5, 75, 22, 30 },
        { 46, 75, 22, 30 }
    };

    int counter = 0;
    int subcounter = 0;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::A: // A key pressed
                    mario_position.x -= 10;
                    break;
                case sf::Keyboard::D: // D key pressed
                    mario_position.x += 10;
                    break;
                default:
                    break;
                }
            }
        }

        window.setActive();

        // update
        mario_sprite.setPosition(mario_position);

        subcounter++;
        if (subcounter >= 1000) {
            counter++;
            subcounter = 0;
        }

        sf::IntRect currentTextureRect;

        if (counter % 2)
            currentTextureRect = frejmovi[0];
        else
            currentTextureRect = frejmovi[1];

        mario_sprite.setTextureRect(currentTextureRect);

        // draw
        window.clear(sf::Color::White);
        window.draw(mario_sprite);


        window.display();
    }
}
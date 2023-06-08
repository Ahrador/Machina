#include <iostream>
#include <SFML/Window.hpp> // include cijeli Window module
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

// Simple and fast zadatak (SFML)

/*
Koristeći javno dostupnu SFML biblioteku, napravi program koji stvori prozor na ekranu, 
a u tom prozoru se prikazuje slika koja ti je najdraža.
*/

int main()
{
    // Stvaranje prozora
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moj omiljeni prozor");
    window.clear(sf::Color::White); // Set window background to white 

    // Učitavanje slike
    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/Alen/Desktop/Coding/byard.png")) {
        return -1; // Provjera j li slika uspješno učitana
    }

    // Stvaranje spritea za prikaz slike
    sf::Sprite sprite(texture);

    // Center the image within the window 
    sprite.setPosition((window.getSize().x - sprite.getLocalBounds().width) / 2, (window.getSize().y - sprite.getLocalBounds().height) / 2);


    // Glavna petlja programa
    while (window.isOpen())
    {
        // Provjera događaja
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Brisanje prozora
        window.clear(sf::Color::White); // Clear the window with white color 

        // Crtanje spritea na prozoru
        window.draw(sprite);

        // Prikazivanje promjena
        window.display();
    }

    return 0;
}
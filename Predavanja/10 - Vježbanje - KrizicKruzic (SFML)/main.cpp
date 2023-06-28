#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Krizic Kruzic (SFML)

int main() {
	sf::RenderWindow prozor(sf::VideoMode(500, 451), "Krizic kruzic");

	// data model
	char playing_field[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	const sf::Vector2f koordinate[9] = {
		{0,   0}, { 175,   0}, {340,   0},
		{0, 160}, { 175, 160}, {340, 160},
		{0, 280}, { 175, 280}, {340, 280},
	};

	// svaki put random konfiguracija polja
	srand(time(NULL));
	if (false)
		for (int i = 0; i < 9; i++)
		{
			auto selector = (rand() % 3); // 0, 1, ili 2
			// ?:
			// (test) ? (true_value) : (false_value) ;
			playing_field[i] =
				selector == 0
				? 'x'
				:
				(selector == 1
					? 'o'
					: ' ');
		}

	sf::Texture field_texture;
	field_texture.loadFromFile("C:\\Users\\Alen\\Desktop\\SFML_tictactoe\\igraliste.png");

	sf::Texture krizic_texture;
	krizic_texture.loadFromFile("C:\\Users\\Alen\\Desktop\\SFML_tictactoe\\krizic.png");
	sf::Texture kruzic_texture;
	kruzic_texture.loadFromFile("C:\\Users\\Alen\\Desktop\\SFML_tictactoe\\kockic.png");

	sf::Sprite background_sprite(field_texture);
	sf::Sprite sprite_x(krizic_texture);
	sprite_x.setScale(0.35, 0.35);
	sf::Sprite sprite_o(kruzic_texture);
	sprite_o.setScale(0.35, 0.35);

	char current_player = 'x';

	// main game loop (drawing a single frame)
	while (prozor.isOpen())
	{
		// event handling (user input handling)
		sf::Event event;
		while (prozor.pollEvent(event)) {
			if (event.type == sf::Event::EventType::MouseMoved) {
				// mouse moved, react!
				std::cout << "[MouseMoved] " <<
					"x: " << event.mouseMove.x
					<< ", y : " << event.mouseMove.y << std::endl;
			}
			if (event.type == sf::Event::EventType::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					// igrac stisnuo lijevu tipku misa

					auto clicked_element_index = (event.mouseButton.x / 167) + (event.mouseButton.y / 150) * 3;
					if (clicked_element_index <= 8) { // don't go out of bounds!!!
						std::cout << "[MouseButtonPressed] " <<
							"clicked element index: " << clicked_element_index
							<< std::endl;

						// ako je prazno polje...
						if (playing_field[clicked_element_index] == ' ')
						{
							// ... upisi znak trenutnog igraca ...
							playing_field[clicked_element_index] = current_player;
							// ... i izmijeni trenutnog igraca
							current_player = (current_player == 'x') ? 'o' : 'x'; // mini-if
						}
					}
				}
			}
			if (event.type == sf::Event::Closed) {
				prozor.close();
			}
		}

		// game logic ("update" section of main game loop)
		// TODO

		/* DODATI: polozaj sprite-a (x ili o) se mijenja ovisno o polju koje se ispituje/crta */


		// present items on window
		prozor.draw(background_sprite);
		// x = 0, y = 0

		for (int i = 0; i < 9; i++) {
			auto trenutni_element = playing_field[i];
			auto trenutna_koordinate = koordinate[i];
			switch (trenutni_element) // x = 330, y = 274
			{
			case 'x':
				sprite_x.setPosition(trenutna_koordinate);
				prozor.draw(sprite_x);
				break;
			case 'o':
				sprite_o.setPosition(trenutna_koordinate);
				prozor.draw(sprite_o); // utiskivanje sprite-a u prozo
				break;
			default:
				break;
			}
		}

		prozor.display();
	}
}

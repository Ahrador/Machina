#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Tetris (SFML)

//Tetromino je element igre Tetris koji se sastoji od 4 bloka
struct Tetromino {
	// 4 tocke koje predstavljaju pozicije blokova unutar igralista
	sf::Vector2i block_position[4];
	enum class ShapeName
	{
		T, L, S, N, J, O, I
	} shape;

	enum class Rotation {
		Bottom, Left, Top, Right
	} rotation;

	Tetromino() {}
	Tetromino(std::vector <sf::Vector2i> argument, ShapeName shape, Rotation rotation)
		: shape(shape), rotation(rotation)
	{
		// for petlja kojom podatke iz argumenta konstruktora prebacujemo unutar objekta
		for (auto i = 0; i < 4; i++)
			block_position[i] = argument[i]; // spremi iz argumenta u objekt
	}
};



int main() {
	bool igraliste[10][7] = { 0 }; // false = nema bloka, true = ima bloka

	sf::RenderWindow prozor(sf::VideoMode(1500, 1000), "Krizic kruzic");
	prozor.setPosition({ 340, 3 });

	sf::Texture block_image;
	block_image.loadFromFile("C:/bojan/tetris_block.png");

	sf::Sprite block_sprite(block_image);

	// config variables
	const auto block_offset = 150;
	const auto falling_speed = 3;
	const auto last_y_coordinate = 6;


	// "T" element
	Tetromino tetromino({ {2,0}, {3,0}, {4,0}, {3,1} }, Tetromino::ShapeName::T, Tetromino::Rotation::Bottom);

	sf::Clock sat;

	// main game loop
	while (prozor.isOpen())
	{
		sf::Time proteklo_vrijeme = sat.getElapsedTime();

		prozor.clear();

		// event handling (user input handling)
		sf::Event event;
		while (prozor.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				prozor.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					// move left by 1
					if (
						// mora se moci pomaknuti: lijevo svakog bloka Tetromina mora biti prazno mjesto
						igraliste[tetromino.block_position[0].x - 1][tetromino.block_position[0].y] == false &&
						igraliste[tetromino.block_position[1].x - 1][tetromino.block_position[1].y] == false &&
						igraliste[tetromino.block_position[2].x - 1][tetromino.block_position[2].y] == false &&
						igraliste[tetromino.block_position[3].x - 1][tetromino.block_position[3].y] == false

						)
					{
						for (int i = 0; i < 4; i++) {
							tetromino.block_position[i].x--;
						}
					}

					break;
				case sf::Keyboard::D:
					// move right by 1
					if (
						// mora se moci pomaknuti: desno svakog bloka Tetromina mora biti prazno mjesto
						igraliste[tetromino.block_position[0].x + 1][tetromino.block_position[0].y] == false &&
						igraliste[tetromino.block_position[1].x + 1][tetromino.block_position[1].y] == false &&
						igraliste[tetromino.block_position[2].x + 1][tetromino.block_position[2].y] == false &&
						igraliste[tetromino.block_position[3].x + 1][tetromino.block_position[3].y] == false

						)
					{
						for (int i = 0; i < 4; i++) {
							tetromino.block_position[i].x++;
						}
					}
					break;
				case sf::Keyboard::Space:
					// rotation is based on shape!
					switch (tetromino.shape)
					{
					case Tetromino::ShapeName::T:
						switch (tetromino.rotation)
						{
						case Tetromino::Rotation::Bottom:
							if (
								igraliste[tetromino.block_position[0].x + 1][tetromino.block_position[0].y - 1] == false &&
								igraliste[tetromino.block_position[2].x - 1][tetromino.block_position[2].y + 1] == false &&
								igraliste[tetromino.block_position[3].x - 1][tetromino.block_position[3].y - 1] == false
								) {
								tetromino.block_position[0].x += 1;
								tetromino.block_position[0].y -= 1;

								tetromino.block_position[2].x -= 1;
								tetromino.block_position[2].y += 1;

								tetromino.block_position[3].x -= 1;
								tetromino.block_position[3].y -= 1;
								// zapamti da sad gleda u lijevo
								tetromino.rotation = Tetromino::Rotation::Left;
							}
							break;
						case Tetromino::Rotation::Left:
							if (true) {
								tetromino.block_position[0].x += 1;
								tetromino.block_position[0].y += 1;

								tetromino.block_position[2].x -= 1;
								tetromino.block_position[2].y -= 1;

								tetromino.block_position[3].x += 1;
								tetromino.block_position[3].y -= 1;
								// zapamti da sad gleda u lijevo
								tetromino.rotation = Tetromino::Rotation::Top;
							}
							break;
						case Tetromino::Rotation::Top:
							if (true) {
								tetromino.block_position[0].x -= 1;
								tetromino.block_position[0].y += 1;

								tetromino.block_position[2].x += 1;
								tetromino.block_position[2].y -= 1;

								tetromino.block_position[3].x += 1;
								tetromino.block_position[3].y += 1;
								// zapamti da sad gleda u lijevo
								tetromino.rotation = Tetromino::Rotation::Right;
							}
							break;
						case Tetromino::Rotation::Right:
							if (true) {
								tetromino.block_position[0].x -= 1;
								tetromino.block_position[0].y -= 1;

								tetromino.block_position[2].x += 1;
								tetromino.block_position[2].y += 1;

								tetromino.block_position[3].x -= 1;
								tetromino.block_position[3].y += 1;
								// zapamti da sad gleda u lijevo
								tetromino.rotation = Tetromino::Rotation::Bottom;
							}
							break;
						default:
							break;
						}
						break;
					case Tetromino::ShapeName::J:
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;
			}
		}

		// update world
		if (proteklo_vrijeme.asSeconds() >= falling_speed) {
			// proslo 2 sekunde, spusti block za 1

			// probat spustit (ako ne ide, postanu dio glavnog igralista)
			if (
				// posebni uvjet - ako je tetromino vec na dnu, ne moze ici nize
				!(
					tetromino.block_position[0].y >= last_y_coordinate ||
					tetromino.block_position[1].y >= last_y_coordinate ||
					tetromino.block_position[2].y >= last_y_coordinate ||
					tetromino.block_position[3].y >= last_y_coordinate
					) &&
				// mora se moci spustiti: ispod svakog bloka Tetromina mora biti prazno mjesto u igralistu
				igraliste[tetromino.block_position[0].x][tetromino.block_position[0].y + 1] == false &&
				igraliste[tetromino.block_position[1].x][tetromino.block_position[1].y + 1] == false &&
				igraliste[tetromino.block_position[2].x][tetromino.block_position[2].y + 1] == false &&
				igraliste[tetromino.block_position[3].x][tetromino.block_position[3].y + 1] == false
				) {
				// moze se spustit
				for (int i = 0; i < 4; i++) {
					tetromino.block_position[i].y++;
				}
			}
			else {
				// ne moze se spustit

				// "upecati" tetromino u igraliste
				for (int i = 0; i < 4; i++) {
					auto tocka_bloka = tetromino.block_position[i];
					igraliste[tocka_bloka.x][tocka_bloka.y] = true;
				}

				// TODO: je li se napunio red? ako da, izbrisi red, i spusti sve u igralistu iznad tog reda

				// "spawnaj" novi tetromino
				// TODO: ako ne moze spawn novog Tetromina, aktiviraj "game over" state
				tetromino = Tetromino({
					{5,0},{6,0},{7,0},{7,1}
					}, Tetromino::ShapeName::J, Tetromino::Rotation::Bottom);
			}

			// resetiraj brojac proteklog vremena
			sat.restart();
		}


		// draw world
		// draw tetromino
		for (int i = 0; i < 4; i++) {
			auto position = tetromino.block_position[i];
			block_sprite.setPosition(position.x * block_offset, position.y * block_offset);
			prozor.draw(block_sprite);
		}

		// draw playing field
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 7; j++) {
				// ako je na igralistu "zabiljezen" blok na toj poziciji, nacrtaj ga
				if (igraliste[i][j] == true)
				{
					sf::Vector2i position = { i, j };
					block_sprite.setPosition(position.x * block_offset, position.y * block_offset);
					prozor.draw(block_sprite);
				}
			}
		}


		prozor.display();
	}

}

#include <iostream>
#include <Windows.h>

struct Position { int x, y; };

struct ChessPiece {
	enum class Color { WHITE, BLACK } color;
	//enum class Type { KING, QUEEN, KNIGHT, BISHOP, ROOK, PAWN };
};

struct King {
	enum class Color { WHITE, BLACK } color;
	Position position;

	bool canMoveToPosition(Position nextMove)
	{
		// ne mogu se pomaknuti na svoju trenutnu poziciju!
		if (nextMove.x == position.x && nextMove.y == position.y)
			return false;


		// ako se kralj moze pomaknuti, ...
		if (
			(
				// ako je njihova razlika jednaka 1 ili manje (0)
				abs(nextMove.x - position.x) <= 1
				/*
				nextMove.x - position.x == 1
				|| nextMove.x - position.x == 0 // nextMove.x == position.x
				|| nextMove.x - position.x == -1
				*/
				)

			&&

			(
				nextMove.y - position.y == 1
				|| nextMove.y - position.y == 0 // nextMove.y == position.y
				|| nextMove.y - position.y == -1
				)
			)
		{
			// ... vrati true
			return true;
		}
		// ispalo je da ne moze, vrati false
		return false;
	}
};

struct Knight {
	enum class Color { WHITE, BLACK } color;
	Position position;

	bool canMoveToPosition(Position nextMove)
	{
		// ne mogu se pomaknuti na svoju trenutnu poziciju!
		if (nextMove.x == position.x && nextMove.y == position.y)
			return false;

		if (
			// razlika po x == 1 ako je razlika po y == 2
			(
				abs(nextMove.x - position.x) == 1
				//(nextMove.x - position.x == 1 || nextMove.x - position.x == -1)
				&&
				abs(nextMove.y - position.y) == 2
				//(nextMove.y - position.y == 2 || nextMove.y - position.y == -2)
				)

			// ILI
			||

			// razlika po x == 2 ako je razlika po y == 1
			(
				(nextMove.x - position.x == 2 || nextMove.x - position.x == -2)
				&&
				(nextMove.y - position.y == 1 || nextMove.y - position.y == -1)
				)


			) {
			return true;
		}

		return false;
	}
};

int main() {
	Knight white_knight;
	//white_knight.color = King::Color::WHITE;

	srand(time(NULL));

	while (true) {
		white_knight.position = { rand() % 8, rand() % 8 };

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
			{
				Position nextMove = { j, i };
				if (white_knight.canMoveToPosition(nextMove)) {
					std::cout << "T";
				}
				else {
					std::cout << "F";
				}
			}
			std::cout << std::endl;
		}
		std::cout << "King is at " << white_knight.position.x << " , " << white_knight.position.y << std::endl;
		std::cout << "---------------------" << std::endl;

		Sleep(3000);
	}

}
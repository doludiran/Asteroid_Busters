//
//  main.cpp
//

#include "Buffer.h"
#include "player.h"
#include "asteroid.h"
#include "planet.h"

bool isCollision(const Player & my_player, const Asteroid & my_asteroid);

int main()
{
	
	srand((unsigned)time(0));
	Planet my_planet;
	Player my_player;
	Asteroid my_asteroid;
	Buffer mybuffer;
	unsigned int player_row = 10, player_column = 1;
	unsigned int asteroid_row = 5, asteroid_column = 30;
	int current_column = 0;

	PlanetLoadImage();
	PlayerLoadImage();
	planetInIt(my_planet);
	playerInIt(my_player);
	playerSetPosition(my_player, player_row, player_column);
	asteroidLoadImage();
	asteroidInIt(my_asteroid);
	asteroidSetPosition(my_asteroid, asteroid_row, asteroid_column);
	asteroidRandomizeOreValue(my_asteroid);

	bool continue_game = true;

	string commandline;
	while (continue_game)
	{
		// display current state of the game
		bufferClear(mybuffer);
		planetDraw(my_planet, mybuffer, current_column);
		playerDraw(my_player, mybuffer, current_column);
		asteroidDraw(my_asteroid, mybuffer, current_column);
		bufferPrint(mybuffer);
		playerPrintStatusRow(my_player);

		cout << "Next? ";
		getline(cin, commandline, '\n');
		if (commandline.length() > 0)
		{
			switch (commandline[0])
			{
			case 'q':
			case 'Q':
				continue_game = false;
				break;
			case 'w':
			case 'W':
				playerMove(my_player, -1, 1);
				current_column++;
				if (playerGetRow(my_player) < 0 )
					playerMove(my_player, 1, 0);
				break;
			case 's':
			case 'S':
				playerMove(my_player, 0, 1);
				current_column++;
				break;
			case 'x':
			case 'X':
				playerMove(my_player, 0, 1);
				current_column++;
				if (playerGetRow(my_player) + playerGetRowSize(my_player) < BUFFER_ROWS)
					playerMove(my_player, 1, 0);
				break;
				playerUpdate(my_player);

			}
		}
			if (isCollision(my_player, my_asteroid) == true)
			{
				playerReduceShieldStrength(my_player, asteroidGetOreValue(my_asteroid));
				playerIncreaseOreCollected(my_player, asteroidGetOreValue(my_asteroid));
				asteroidMarkDead(my_asteroid);
			}
			if (asteroidIsDead(my_asteroid))
			{
				asteroidRandomizeOreValue(my_asteroid);
				asteroidSetPosition(my_asteroid, (0 + rand() % 17 - 0), playerGetColumn(my_player)+ BUFFER_COLUMNS - 3);
			}
			if (playerIsDead(my_player) == true)
			{
				cout << "Game Over" << endl;
				continue_game = false;
			}
			
			if (current_column == asteroidGetColumn(my_asteroid) )
			{
				asteroidMarkDead(my_asteroid);
			}
	}

	char dummy;
	cout << "Press any key to continue" << endl;
	dummy = getc(stdin);
	return 0;
}


	bool isCollision(const Player & my_player, const Asteroid & my_asteroid)
{
	// determine minimum and maximum rows and columns for player ship and asteroid
	int prmin = playerGetRow(my_player);
	int prmax = playerGetRow(my_player) + playerGetRowSize(my_player) - 1;
	int pcmin = playerGetColumn(my_player);
	int pcmax = playerGetColumn(my_player) + playerGetColumnSize(my_player) - 1;
	int armin = asteroidGetRow(my_asteroid);
	int armax = asteroidGetRow(my_asteroid) + asteroidGetRowSize(my_asteroid) - 1;
	int acmin = asteroidGetColumn(my_asteroid);
	int acmax = asteroidGetColumn(my_asteroid) + asteroidGetColumnSize(my_asteroid) - 1;

	// return false if no collision is possible, e.g., if last row of player ship 
	// (prmax) is before the first row of the asteroid (armin), etc.
	if (prmax < armin) return false;
	if (armax < prmin) return false;
	if (pcmax < acmin) return false;
	if (acmax < pcmin) return false;

	// if the two images are not separated in any way, then they must be colliding
	return true;
}

#include "player.h"


static const int ROWS = 5;
static const int COLUMNS = 7;
static const int MAX_SHIELD_STRENGTH = 50;

static char player_ship_image[ROWS][COLUMNS];

static void printStatusBar(unsigned int length, double fract);

void PlayerLoadImage()
{
	string myline;
	ifstream player_image_data("player.txt");
	if (!player_image_data)
	{
		cerr << "Player image file is not available" << endl;
		return;
	}

	for (unsigned int i = 0; i < ROWS; i++)
	{
		getline(player_image_data, myline, '\n');
		// WRONG: player_image_data.getline(myline, PLAYER_SHIP_COLUMNS);
		if (!player_image_data)
		{
			cerr << "Player image file is missing some data" << endl;
			return;
		}
		for (unsigned int j = 0; j < COLUMNS; j++)
		{
			player_ship_image[i][j] = myline[j];
		}
	}
	player_image_data.close();
}

void playerInIt(Player & p1)
{
	p1.row = 0;
	p1.column = 0;
	p1.row_size = ROWS;
	p1.column_size = COLUMNS;
	p1.shield_strength = MAX_SHIELD_STRENGTH;
	p1.ore_collected = 0;
}

int playerGetRow(const Player & play)
{
	return play.row;
}

int playerGetColumn(const Player & play)
{
	return play.column;
}


int playerGetRowSize(const Player & play)
{
	return play.row_size;
}

int playerGetColumnSize(const Player & play)
{
	return play.column_size;
}

bool playerIsDead(const Player & play)
{
	if (play.shield_strength == 0)
		return true;
	else
		return false;
}

double playerGetShieldStrengthFraction(const Player & play)
{
	double shield = (static_cast<double>(play.shield_strength) / static_cast<double>(MAX_SHIELD_STRENGTH));

		return shield;
}

unsigned int playerGetOreCollected(const Player & play)
{
	return play.ore_collected;
}

void playerDraw(const Player & play, Buffer & bufff, int & dist)
{
	for (unsigned int i = 0; i < ROWS; i++)
	{
		for (unsigned int j = 0; j < COLUMNS; j++)
		{
			bufferSetCell(bufff, player_ship_image[i][j], play.row + i, play.column + j - dist);
		}
	}
}

void playerSetPosition(Player & play, int rowa, int columna)
{
	play.row = rowa;
	play.column = columna;
}

void playerMove(Player & play, int rowb, int columnb)
{
	play.row += rowb;
	play.column += columnb;
}

void playerReduceShieldStrength(Player & play, unsigned int shield)
{
	if (play.shield_strength > shield)
		play.shield_strength -= shield;
	else
		play.shield_strength = 0;
}

void playerIncreaseOreCollected(Player & play, unsigned int ore)
{
	play.ore_collected += ore;
}

void playerUpdate(Player & play)
{
	if (play.shield_strength < MAX_SHIELD_STRENGTH)
		play.shield_strength++;
}

void printStatusBar(unsigned int length, double fract)
{
	cout << "|";
	for (int i = 0; i < fract * (length - 2); i++)
		cout << "*";
	for (int j = 0; j < (length - 2) - (fract * (length - 2)); j++)
		cout << "-";
	cout << "|";
}

void playerPrintStatusRow(const Player & play)
{
	cout << "shields";
	printStatusBar(22, playerGetShieldStrengthFraction(play));
	cout << "Power";
	printStatusBar(9, playerGetShieldStrengthFraction(play));
	cout << "ore:";
	cout << setw(6) << setfill('0') << play.ore_collected << "\n";
}
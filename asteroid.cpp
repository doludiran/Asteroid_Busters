#include "asteroid.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

static const int ORE_VALUE_DEAD = 0;
static const int ORE_VALUE_MIN = 1;
static const int ORE_VALUE_MAX = 80;
static const int ROWS = 3;
static const int COLUMNS = 4;
static char asteroid_image[ROWS][COLUMNS];


void asteroidLoadImage()
{
	string myline;
	ifstream asteroid_image_data("asteroid.txt");
	if (asteroid_image_data.fail())
	{
		cerr << "Asteroid image file is not available" << endl;
		return;
	}

	for (unsigned int i = 0; i < ROWS; i++)
	{
		getline(asteroid_image_data, myline, '\n');
		if (!asteroid_image_data)
		{
			cerr << "Asteroid image file is missing some data" << endl;
			return;
		}
		for (unsigned int j = 0; j < COLUMNS; j++)
		{
			asteroid_image[i][j] = myline[j];
		}
	}
	asteroid_image_data.close();
}


void asteroidInIt(Asteroid & a1)
{
	a1.row = 0;
	a1.column = 0;
	a1.row_size = ROWS;
	a1.column_size = COLUMNS;
	a1.ore_value = 0;
}

int asteroidGetRow(const Asteroid & aster)
{
	return aster.row;
}

int asteroidGetColumn(const Asteroid & aster)
{
	return aster.column;
}


int asteroidGetRowSize(const Asteroid & aster)
{
	return aster.row_size;
}

int asteroidGetColumnSize(const Asteroid & aster)
{
	return aster.column_size;
}

bool asteroidIsDead(const Asteroid & aster)
{
	if (aster.ore_value == ORE_VALUE_DEAD)
		return true;
	else
		return false;
}

unsigned int asteroidGetOreValue(const Asteroid & aster)
{
	return aster.ore_value;
}

void asteroidDraw(const Asteroid & aster, Buffer & buff, int & dist1)
{
	string alp;
	string bet;
	if (asteroidGetOreValue(aster) > 9)
	{
		alp = to_string(asteroidGetOreValue(aster) / 10);
		bet = to_string(asteroidGetOreValue(aster) % 10);
	}
	else if (asteroidGetOreValue(aster) < 10)
	{
		alp = "0";
		bet = to_string(asteroidGetOreValue(aster));

	}
	for (unsigned int i = 0; i < ROWS; i++)
	{
		for (unsigned int j = 0; j < COLUMNS; j++)
		{
			bufferSetCell(buff, asteroid_image[i][j], aster.row + i, aster.column + j - dist1);
			if (i == 1 && j == 1)
			{
				bufferSetCell(buff, alp[0], asteroidGetRow(aster) + i, asteroidGetColumn(aster) + j - dist1);
			}
			else if (i == 1 && j == 2)
			{
				bufferSetCell(buff, bet[0], asteroidGetRow(aster) + i, asteroidGetColumn(aster) + j - dist1);
			}
		}
	}
}
void asteroidSetPosition(Asteroid & aster, int rowa, int columna)
{
	aster.row = rowa;
	aster.column = columna;
}

void asteroidMove(Asteroid & aster, int rowb, int columnb)
{
	aster.row += rowb;
	aster.column += columnb;
}

void asteroidRandomizeOreValue(Asteroid & aster)
{
	srand((unsigned)time(0));
	aster.ore_value = ORE_VALUE_MIN + rand() % ORE_VALUE_MAX - ORE_VALUE_MIN;
}

void asteroidMarkDead(Asteroid & aster)
{
	aster.ore_value = ORE_VALUE_DEAD;
}


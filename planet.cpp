#include "planet.h"


static const int ROWS = 14;
static const int COLUMNS = 60;


static char planet[ROWS][COLUMNS];



void PlanetLoadImage()
{
	string myline;
	ifstream planet_image_data("planet.txt");
	if (!planet_image_data)
	{
		cerr << "Planet image file is not available" << endl;
		return;
	}

	for (unsigned int i = 0; i < ROWS; i++)
	{
		getline(planet_image_data, myline, '\n');
		// WRONG: player_image_data.getline(myline, PLAYER_SHIP_COLUMNS);
		if (!planet_image_data)
		{
			cerr << "Player image file is missing some data" << endl;
			return;
		}
		for (unsigned int j = 0; j < COLUMNS; j++)
		{
			planet[i][j] = myline[j];
		}
	}
	planet_image_data.close();
}

void planetInIt(Planet & pl)
{
	pl.row = 0;
	pl.column = 0;
	pl.row_size = ROWS;
	pl.column_size = COLUMNS;
	
}



void planetDraw(const Planet & plan, Buffer & bufff, int & dist)
{
	for (unsigned int i = 0; i < ROWS; i++)
	{
		for (unsigned int j = 0; j < COLUMNS; j++)
		{
			bufferSetCell(bufff, planet[i][j], plan.row + i, plan.column + j - dist);
		}
	}
}


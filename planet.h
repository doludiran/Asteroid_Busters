#include "Buffer.h"


using namespace std;


struct Planet
{
	int row;
	int column;
	int row_size;
	int column_size;
	
};

void PlanetLoadImage();
void planetInIt(Planet & p1);
void planetDraw(const Planet & plan, Buffer & bufff, int & dist);

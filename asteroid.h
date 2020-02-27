#include<iostream>
#include"Buffer.h"
using namespace std;


struct Asteroid
{
	int row;
	int column;
	int row_size;
	int column_size;
	unsigned int ore_value;
};

void asteroidLoadImage();
void asteroidInIt(Asteroid & a1);
int asteroidGetRow(const Asteroid & aster);
int asteroidGetColumn(const Asteroid & aster);
int asteroidGetRowSize(const Asteroid & aster);
int asteroidGetColumnSize(const Asteroid & aster);
bool asteroidIsDead(const Asteroid & aster);
unsigned int asteroidGetOreValue(const Asteroid & aster);
void asteroidDraw(const Asteroid & aster, Buffer & buff, int & dist1);
void asteroidSetPosition(Asteroid & aster, int rowa, int columna);
void asteroidMove(Asteroid & aster, int rowb, int columnb);
void asteroidRandomizeOreValue(Asteroid & aster);
void asteroidMarkDead(Asteroid & aster);


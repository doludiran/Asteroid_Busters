

#include "Buffer.h"


using namespace std;


struct Player
{
	int row;
	int column;
	int row_size;
	int column_size;
	unsigned int shield_strength;
	unsigned int ore_collected;
};

void PlayerLoadImage();
void playerInIt(Player & p1);
int playerGetRow(const Player & play);
int playerGetColumn(const Player & play);
int playerGetRowSize(const Player & play);
int playerGetColumnSize(const Player & play);
bool playerIsDead(const Player & play);
double playerGetShieldStrengthFraction(const Player & play);
unsigned int playerGetOreCollected(const Player & play);
void playerDraw(const Player& play, Buffer& bufff, int & dist);
void playerSetPosition(Player & play, int rowa, int columna);
void playerMove(Player & play, int rowb, int columnb);
void playerReduceShieldStrength(Player & play, unsigned int shield);
void playerIncreaseOreCollected(Player & play, unsigned int ore);
void playerUpdate(Player & play);
void playerPrintStatusRow(const Player & play);

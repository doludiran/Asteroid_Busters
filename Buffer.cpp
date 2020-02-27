//
//  Buffer.cpp
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Buffer.h"

const char BUFFER_EMPTY = ' ';
const char BUFFER_BORDER = '#';

void bufferClear(Buffer b)
{
	for (unsigned int i = 0; i < BUFFER_ROWS; i++)
	{
		for (unsigned int j = 0; j < BUFFER_COLUMNS; j++)
		{
			b[i][j] = BUFFER_EMPTY;
		}
	}
}

void bufferPrint(Buffer b)
{
	// print first row of # symbols
	for (unsigned int j = 0; j < BUFFER_COLUMNS + 2; j++)
	{
		cout << BUFFER_BORDER;
	}
	cout << endl;

	// print content of buffer with # symbol before and after each row
	for (unsigned int i = 0; i < BUFFER_ROWS; i++)
	{
		cout << BUFFER_BORDER;
		for (unsigned int j = 0; j < BUFFER_COLUMNS; j++)
		{
			cout << b[i][j];
		}
		cout << BUFFER_BORDER;
		cout << endl;
	}

	// print first row of # symbols
	for (unsigned int j = 0; j < BUFFER_COLUMNS + 2; j++)
	{
		cout << BUFFER_BORDER;
	}
	cout << endl;
}

void bufferSetCell(Buffer b, char c, int row, int column)
{
	
	{

		b[row][column] = c;
	}
}

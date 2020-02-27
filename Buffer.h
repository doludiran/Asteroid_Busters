//
//  Buffer.h
//
#ifndef __BUFFER_H_
#define __BUFFER_H_

#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


const int BUFFER_ROWS = 20;
const int BUFFER_COLUMNS = 60;
typedef char Buffer[BUFFER_ROWS][BUFFER_COLUMNS];

void bufferClear(Buffer b);
void bufferPrint(Buffer b);
void bufferSetCell(Buffer b, char c, int row, int column);

#endif

#pragma once
#include "Cell.h"
#include <cliext\vector>

using cliext::vector;


/*  Class for representation of table
 */

public ref class Table {
private:

	// Demensions of table
	unsigned int height;
	unsigned int width;

	// Table
	vector < vector <Cell^>^ > table;

public:

	Table(unsigned int height, unsigned int width);


	// Getters of values
	unsigned int getHeight(void);
	unsigned int getWidth(void);

	vector <Cell^>^ operator[] (int index);

	// Changers of demensions
	void changeHeight(int delta);
	void changeWidth(int delta);

};
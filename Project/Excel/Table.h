#pragma once
#include "Cell.h"
#include <cliext\vector>
#include "Graph.h"

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

	// Graph class for recalculation dependent cells
	Graph^ graph;

public:

	Table(unsigned int height, unsigned int width);


	// Getters of values
	unsigned int getHeight(void);
	unsigned int getWidth(void);

	vector <Cell^>^ operator[] (unsigned int index);

	// Changers of demensions
	void changeHeight(int delta);
	void changeWidth(int delta);

	Graph^ getGraph(void);

};
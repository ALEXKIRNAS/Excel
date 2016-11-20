#include "Table.h"

/*  Constructor of class Table
 *  Input: Takes height and width of created/loaded table
 *  Allocate memory for table
 */
Table::Table(unsigned int height, unsigned int width) {
	this->height = height;
	this->width = width;

	table.resize(height);

	for (int i = 0; i < height; i++) {
		table[i] = gcnew vector <Cell^>(width);

		for (int z = 0; z < width; z++)
			table[i][z] = gcnew Cell;
	}

	graph = gcnew Graph(height, width);
}

/*  Getter for height atribute
 */
unsigned int Table::getHeight(void) {
	return height;
}

/*  Getter for width atribute
 */
unsigned int Table::getWidth(void) {
	return width;
}

/*  Overload operation [] for direct access to elements
 */
vector <Cell^>^ Table::operator[] (unsigned int index) {
	return table[index];
}

/*  Change height to some delta
 */
void Table::changeHeight(int delta) {
	height += delta;
}

/*  Change width to some delta
*/
void Table::changeWidth(int delta) {
	width += delta;
}

Graph^ Table::getGraph(void) {
	return graph;
}
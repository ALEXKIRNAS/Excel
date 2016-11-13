#include "Cell.h"

Cell::Cell(void) : value(nullptr), result(0) {}

/*  Change current value of object
 */
void Cell::change(String^ str) {
	value = String::Copy(str);
}
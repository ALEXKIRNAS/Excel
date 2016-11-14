#include "Cell.h"

Cell::Cell(void) : value(nullptr), result(0), isFormula(true) {}

/*  Change current value of object
 */
void Cell::change(String^ str) {
	value = String::Copy(str);
}

double Cell::getResult(void) {
	if (isFormula) return result;
	else throw "#Unable to calc expresion";
}
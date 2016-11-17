#include "Cell.h"

Cell::Cell(void) : value(L""), result(0), isFormula(true) {}


void Cell::setValue(Object^ str) {
	value = String::Copy(Convert::ToString(str));
}

String^ Cell::getValue(void) {
	if (value)
	return value;
	return gcnew String("");
}

Number Cell::getResult(void) {
	if (isFormula) return result;
	else throw "#Unable to calc expresion";
}

void Cell::setResult(Number res) {
	result = res;
}

void Cell::setIsFormula(bool flag) {
	isFormula = flag;
}

bool Cell::getIsFormula(void) {
	return isFormula;
}
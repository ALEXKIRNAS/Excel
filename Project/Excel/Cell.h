#pragma once
#include "Number.h"

using namespace System;


/* Class for represenation cell of table
 */
public ref class Cell {
private:

	// Value that contains cell
	String^ value;

	// Result of formula calculation
	Number result;

	// Variable that shows is cell contains formula
	bool isFormula;

public:
	Cell(void);

	void setValue(Object^ str);
	String^ getValue(void);

	Number getResult(void);
	void setResult(Number res);

	void setIsFormula(bool flag);
	bool getIsFormula(void);

};
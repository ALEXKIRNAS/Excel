#pragma once
#include "Number.h"

using System::String;


/* Class for represenation cell of table
 */
public ref class Cell {
private:

	// Value that contains cell
	String^ value;

	// Result of formula calculation
	Number result;

	// Variable that show is cell contains formula
	bool isFormula;

public:
	Cell(void);

	void change(String^ str);
	double getResult(void);

};
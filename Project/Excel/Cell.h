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

public:
	Cell(void);

	void change(String^ str);

};
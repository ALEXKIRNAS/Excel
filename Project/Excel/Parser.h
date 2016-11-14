#pragma once
#include "Number.h"
#include "Table.h"
#include <string>

using std::string;

string shuntingYard(const string& input);
unsigned int opPrior(const char& ch);
Number parse(const string& input,Table^ table);
bool isElemOper(const char& ch);
int getX_index(string& str, int index = 0);
int getY_index(string& str, int index = 0);
bool strcmp(string& str, int index, int element);
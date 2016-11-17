#pragma once
#include "Number.h"
#include "Table.h"
#include <string>

using std::wstring;

wstring shuntingYard(const wstring& input);
unsigned int opPrior(const wchar_t& ch);
Number parse(const wstring& input,Table^ table);
bool isElemOper(const wchar_t& ch);
int getX_index(wstring& str, int index = 0);
int getY_index(wstring& str, int index = 0);
bool strcmp(wstring& str, int index, int element);
#pragma once
#include "Number.h"
#include "Table.h"
#include <string>
#include <stack>

using std::wstring;
using std::stack;

class Parser {
private:
	static wstring shuntingYard(const wstring& input);

	inline static unsigned int opPrior(const wchar_t& ch);
	inline static bool isElemOper(const wchar_t& ch);
	inline static int getX_index(wstring& str, int index = 0);
	inline static int getY_index(wstring& str, int index = 0);
	inline static bool strcmp(wstring& str, int index, int element);

	static void processNumbers(const wstring& input, wstring& output, unsigned int& i);
	static void processCloseBracket(const wstring& input, wstring& output, stack<wstring>& aStack, unsigned int& i);
	static void processElemOperations(const wstring& input, wstring& output, stack<wstring>& aStack, unsigned int& i);
	static void processLink(const wstring& input, wstring& output, unsigned int& i);
	static void processFunctions(const wstring& input, wstring& output, stack<wstring>& aStack, unsigned int& i);

	static void calculateNumber(wstring& output, stack<Number>& aStack, size_t& i);
	static void calculateLink(Table^ table, wstring& output, stack<Number>& aStack, size_t& i);
	static void calculateElemOperations(wstring& output, stack<Number>& aStack, size_t& i);
	static void calculateFunctions(wstring& output, stack<Number>& aStack, size_t& i);

	static int searchAssigmentSymbol(const wstring& input);
	static Number caseFuction(Number& top, int index);
	static Number isOnlyOneDigit(const wstring& input, int i);

public:
	static Number parse(const wstring& input, Table^ table);
};
#include "Parser.h"
#include <math.h>
#define CODE_OF_STRING 0 // Defining code of simple string (no formula)
#define CODE_OF_EMPTY_STRING 1 // Defining code of empty input string

#define pression 4 // Number of symbols after point
#define eps 1e-7 // Number zero
#define M_PI       3.14159265358979323846   // pi

#define numOfFunc sizeof(func)/sizeof(char *)
const wstring func[] = {
	L"sin", 
	L"cos", 
	L"tan",
	L"ctg",
	L"ln",
	L"exp",
	L"asin",
	L"acos",
	L"atan",
	L"actg"
};


using std::stack;
using System::Convert;

/*  Rewrite expresion in postfix notation 
 *  using Shunting-yard algorithm
 */
wstring Parser::shuntingYard(const wstring& input) {
	// Stack for operations and functions
	stack<wstring> aStack; 

	// Output string in postfix notation
	wstring output(L"");

	unsigned int length = input.length();
	unsigned int i = 0;

	while(i < length) {
		// Skip space symbols
		while (isspace(input[i])) i++;
		if (i == length) break;

		// Process number
		if (isdigit(input[i]) || (input[i] == '-' && i == 0) || (i > 0 && !aStack.empty() && aStack.top()[0] == L'(' && input[i] == L'-'))
			processNumbers(input, output, i);

		// Process open bracket
		else if (input[i] == L'(')
			aStack.push(wstring(L"("));

		// Process close bracket
		else if (input[i] == L')')
			processCloseBracket(input, output, aStack, i);

		// If elementary operation +, -, *, /, ^
		else if (isElemOper(input[i]))
			processElemOperations(input, output, aStack, i);

		// Process link
		else if (input[i] == L'$')
			processLink(input, output, i);

		// Process functions
		else if (isalpha(input[i]))
			processFunctions(input, output, aStack, i);

		// invalid input format
		else throw "#Invalid input format";

		i++;
	}

	while (!aStack.empty()) {
		output += aStack.top() += L" ";
		aStack.pop();
	}

	return output;
}

/* Cheaching elementary operation priority
 */
unsigned int Parser::opPrior(const wchar_t& ch) {
	switch (ch){
		case '^':
					return 3;
		case '*':
		case '/':
					return 2;
		case '+':
		case '-':
					return 1;
	}
}

/*  Function for parsing math expresion
 */
Number Parser::parse(const wstring& input, Table^ table) {
	int index;

	try {
		index = searchAssigmentSymbol(input);
	}
	catch (Number x) {
		return x;
	}

	// Deleting all symbols in [0; index]
	wstring simpleInput = input.substr(index, input.size() - index + 1); 
	wstring output = shuntingYard(simpleInput);

	stack <Number> aStack;

	size_t i = 0;
	size_t length = output.size();

	while (i < length) {
		if (isspace(output[i])) i++;
		if (i == length) break;

		// Calculate number and push it in the stack
		else if (isdigit(output[i]))
			calculateNumber(output, aStack, i);

		// Select from table number from link and push it in the stack
		else if (output[i] == L'$')
			calculateLink(table, output, aStack, i);

		// Release elementary operations with stack elements
		else if (isElemOper(output[i]))
			calculateElemOperations(output, aStack, i);

		else calculateFunctions(output, aStack, i);
	}

	if (aStack.empty()) throw "#Bad expresion";

	// Cat more that pression symbols after point
	return roundl(aStack.top() * pow(static_cast<Number> (10), pression)) / pow(static_cast<Number> (10), pression);
}

/*  Cheacking is operation is elementary (+, -, *, /, ^)
 */
bool Parser::isElemOper(const wchar_t& ch) {
	return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '^');
}

/*  Conver Y_index of table cell to digit
 */
int Parser::getY_index(wstring& str, int index) {

	int res = 0;
	int i = index;
	while (str[i] != '$') i++;

	if (i - index > 7) throw "#Index out of range";

	while (str[index] != '$') res = res * 26 + str[index++] - 'A';
	return res + 1;
}

/*  Conver X_index of table cell to digit
 */
int Parser::getX_index(wstring& str, int index) {
	int res = 0;
	int i = index;
	while (isdigit(str[i])) i++;

	if (i - index > 8) throw "#Index out of range";

	while (isdigit(str[index])) res = res * 10 + str[index++] - '0';
	return res - 1;
}

/*  Compare two definishions of functions
 */
bool Parser::strcmp(wstring& str, int index, int element) {
	int i = 0;
	for (int size = str.length(); func[element][i] && i + index <= size; i++)
		if (func[element][i] != str[i + index]) return false;

	if (func[element][i]) return false;
	else return true;
}

/*  Processing nubers literals in input string
 */
void Parser::processNumbers(const wstring& input, wstring& output, unsigned int& i) {
	int length = input.size();

	// Adding sign if this nessasary
	if (input[i] == '-') output += L'-';

	// Variable that show is point read already
	bool isPoint = false;

	while (i < length && (isdigit(input[i]) || input[i] == L'.')) {

		if (input[i] == '.') {
			// If adding point for this number not at first time
			if (isPoint) throw "#Bad number";

			output += '.';
			isPoint = true;
		}
		else output += input[i];

		i++;
	}

	output += ' ';
	i--;
}

/*  Processing close bracket
 */
void Parser::processCloseBracket(const wstring& input, wstring& output, stack<wstring>& aStack, unsigned int& i) {
	while (!aStack.empty() && aStack.top()[0] != '(') {
		output += aStack.top() += ' ';
		aStack.pop();
	}

	if (aStack.empty()) throw "#No close  bracket";
	else aStack.pop();
}

/*  Porcessing elementary operations
 */
void Parser::processElemOperations(const wstring& input, wstring& output, stack<wstring>& aStack, unsigned int& i) {
	while (!aStack.empty() && isElemOper(aStack.top()[0]) && (opPrior(aStack.top()[0]) >= opPrior(input[i]))) {
		output += aStack.top() += ' ';
		aStack.pop();
	}

	aStack.push(wstring(L"") += input[i]);
}

/*  Processing links
 */
void Parser::processLink(const wstring& input, wstring& output, unsigned int& i) {
	size_t length = input.size();

	output += '$';

	while (++i < length && input[i] != '$')
		if (input[i] < 'A' || input[i] > 'Z')
			throw "#Bad link name";
		else output += input[i];

		if (i == length) throw "#Bad link name";
		else output += input[i++];

		while (i < length && isdigit(input[i]))
			output += input[i++];

		output += ' ';
		i--;
}

/*  Processing functions
 */
void Parser::processFunctions(const wstring& input, wstring& output, stack<wstring>& aStack, unsigned int& i) {
	wstring func;
	size_t length = input.size();

	while (i < length && isalpha(input[i]))
		func += input[i++];

	// Skip space symbols
	while (i < length && isspace(input[i])) i++;

	if (i == length || input[i] != '(') throw "#No args for function";
	aStack.push(func);
	aStack.push(wstring(L"("));
}

/*  Calulate number and pushing it in the 
 */
void Parser::calculateNumber(wstring& output, stack<Number>& aStack, size_t& i) {
	size_t index = 0;
	aStack.push(std::stod(output.substr(i), &index));
	i += index;
}

/*  Select from table number from link and push it in the stack
 */
void Parser::calculateLink(Table^ table, wstring& output, stack<Number>& aStack, size_t& i) {
	int yIndex = getY_index(output, ++i);

	while (output[i] != '$') i++;
	int xIndex = getX_index(output, ++i);
	while (isdigit(output[i])) i++;

	aStack.push(table[xIndex][yIndex]->getResult());
}

/*  Release elementary operations with stack elements
 */
void  Parser::calculateElemOperations(wstring& output, stack<Number>& aStack, size_t& i) {
	if (aStack.size() < 2) throw "#No arguments";

	Number y = aStack.top();
	aStack.pop();

	Number x = aStack.top();
	aStack.pop();

	switch (output[i]) {
	case '+': aStack.push(x + y); break;
		case '-': aStack.push(x - y); break;
		case '*': aStack.push(x * y); break;
		case '/': {
			if (abs(y - 0) < eps) 
				throw "#Division by zero";
			else 
				aStack.push(x / y); 
			break;
		}
		case '^': aStack.push(pow(x, y)); break;
	}

	i++;
}

/*  Calculate funtions
 */
void  Parser::calculateFunctions(wstring& output, stack<Number>& aStack, size_t& i) {
	if (aStack.size() < 1) throw "#No arguments";
	bool flag = false;

	for (int z = 0; z < numOfFunc; z++)
		if (strcmp(output, i, z)) {
			flag = true;
			Number t = caseFuction(aStack.top(), z);

			// Deliting argument of function
			aStack.pop(); 

			// Pusing result
			aStack.push(t);

			// Set index pointer after funtion name
			i += func[z].size();
			break;
		}

	if (!flag) throw "#Wrong function name";
}

/*  Searching index of assigment symbol in input string
 */
int Parser::searchAssigmentSymbol(const wstring& input) {
	if (input[0] == '\0') throw CODE_OF_EMPTY_STRING;

	try {
		Number x = isOnlyOneDigit(input, 0);
		throw x;
	}
	catch (int x) {
		// Noting to do
	}
	// Searching sybol '='
	for (int i = 0; i < input.size(); i++)
		if (!isspace(input[i]))
			if (input[i] == L'=') return i + 1;
			else throw CODE_OF_STRING; // if first symbol is not space or '=' then this is a general string
}

/*  Computing function value
 */
Number Parser::caseFuction(Number& top, int index) {
	switch (index) {
		// sin
		case 0: return sin(top);
			// cos
		case 1: return cos(top); 
			// tan
		case 2: {
			if (abs(top - M_PI / 2) < eps)
				throw "#Infinity";
			else
				return tan(top);
		}

			// ctg
		case 3: {
			if (abs(top - 0) < eps)
				throw "#Infinity";
			else
				return static_cast<Number> (1) / tan(top);
		}
			// ln
		case 4: {
			// if in segment (- inf; 0] 
			if (top < eps)
				throw "#Ln invalid argument";
			else
				return log(top);
		}

			// exp
		case 5: return exp(top);

			// Asin
		case 6: {
			if (abs(top) - 1 > eps)
				throw "#Asin indvalid arguments";
			else
				return asin(top);
		}
		
			// Acos
		case 7: {
			if (abs(top) - 1 > eps)
				throw "#Acos indvalid arguments";
			else
				return acos(top);
		}

			// Atan
		case 8: return atan(top);

			// Actg
		case 9: return M_PI/static_cast<Number> (2) - atan(top);
		
		default: throw "#Oops. We forgot release function.";
	}
}

/*	Definition is input string consist from one number
 *  Return number or throw exception if not one number
 */
Number Parser::isOnlyOneDigit(const wstring& input, int i) {
	size_t index = 0;
	size_t length = input.size();

	while (i < length && isspace(input[i])) i++;
	if (!isdigit(input[i])) throw 0;
	
	Number t = std::stod(input.substr(i), &index);

	i += index;
	while (i < length && isspace(input[i])) i++;

	if (i != length) throw 0;
	else return t;
}
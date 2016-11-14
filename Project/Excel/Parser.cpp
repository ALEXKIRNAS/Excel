#include "Parser.h"
#include <stack>
#include <ctype.h>
#include <math.h>

#define numOfFunc 3
const string func [] = {
	"sin", "cos", "tan"
};

typedef double(*functions) (double);

functions implementation [] = {
	&sin,
	&cos, 
	&tan
};

using std::stack;
using System::Convert;

/*  Rewrite expresion in postfix notation 
 *  using Shunting-yard algorithm
 */
string shuntingYard(const string& input) {
	// Stack for operations and functions
	stack<string> aStack; 
	// Output string in postfix notation
	string output("");

	unsigned int length = input.length();
	unsigned int i = 0;
	while(i < length) {
		// Skip space symbols
		while (isspace(input[i])) i++;

		// Process number
		if (isdigit(input[i]) || (input[i] == '-' && i == 0) /*|| (i > 0 && input[i - 1] == '(' && input[i] == '-'*/) {

			// Adding sign if this nessasary
			if (input[i] == '-') output += '-';

			// Variable that show is point read already
			bool isPoint = false;

			while (i < length && (isdigit(input[i]) || input[i] == '.')) {

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

		// Process open bracket
		else if (input[i] == '(')
			aStack.push(string("("));

		// Process close bracket
		else if (input[i] == ')') {
			while (!aStack.empty() && aStack.top()[0] != '(') {
				output += aStack.top() += ' ';
				aStack.pop();
			}

			if (aStack.empty()) throw "#No close  bracket";
			else aStack.pop();
		}

		// If elementary operation +, -, *, /, ^
		else if (isElemOper(input[i])) {
			while (!aStack.empty() && isElemOper(aStack.top()[0]) && (opPrior(aStack.top()[0]) >= opPrior(input[i]))) {
				output += aStack.top() += ' ';
				aStack.pop();
			}

			aStack.push(string("") += input[i]);
		}

		// Process link
		else if (input[i] == '$') {
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
		}

		// Process functions
		else if (isalpha(input[i])) {
			string func;

			while (i < length && isalpha(input[i]))
				func += input[i++];

			// Skip space symbols
			while (i < length && input[i] == ' ') i++;

			if (i == length || input[i] != '(') throw "#No args for function";
			aStack.push(func);
			aStack.push(string("("));
		}

		// invalid input format
		else throw "#Invalid input format";

		i++;
	}

	while (!aStack.empty()) {
		output += aStack.top() += " ";
		aStack.pop();
	}

	return output;
}


/* Cheaching elementary operation priority
 */
unsigned int opPrior(const char& ch) {
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
Number parse(const string& input, Table^ table) {
	string output = shuntingYard(input);

	stack <Number> aStack;

	size_t i = 0;
	size_t length = output.size();

	while (i < length) {
		if (isspace(output[i])) i++;
		else if (isdigit(output[i])) {
			size_t index = 0;
			aStack.push(std::stod(output.substr(i), &index));
			i += index;
		}
		else if (output[i] == '$') {
			int xIndex = getX_index(output, ++i);

			while (output[i] != '$') i++;
			int yIndex = getY_index(output, ++i);
			while (isdigit(output[i])) i++;

			aStack.push(table[xIndex][yIndex]->getResult());
		}
		else if (isElemOper(output[i])) {
			if (aStack.size() < 2) throw "#No arguments";

			Number y = aStack.top();
			aStack.pop();

			Number x = aStack.top();
			aStack.pop();

			switch (output[i]){
				case '+': aStack.push(x + y); break;
				case '-': aStack.push(x - y); break;
				case '*': aStack.push(x * y); break;
				case '/': aStack.push(x / y); break;
				case '^': aStack.push(pow(x, y)); break;
			}

			i++;
		}
		else {
			if(aStack.size() < 1) throw "#No arguments";
			bool flag = false;

			for (int z = 0; z < numOfFunc; z++)
				if (strcmp(output, i, z)) {
					flag = true;
					Number t = implementation[z](aStack.top());
					aStack.pop();
					aStack.push(t);
					i += func[z].size();
					break;
				}

			if (!flag) throw "#No such function";
		}

	}

	return aStack.top();
}


/*  Cheacking is operation is elementary (+, -, *, /, ^)
 */
bool isElemOper(const char& ch) {
	return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '^');
}

/*  Conver X_index of table cell to digit
 */
int getX_index(string& str, int index) {

	int res = 0;
	int i = index;
	while (str[i] != '$') i++;

	if (i - index > 7) throw "#Index out of range";

	while (str[index] != '$') res = res * 26 + str[index++] - 'A';
	return res;
}


/*  Conver Y_index of table cell to digit
 */
int getY_index(string& str, int index) {
	int res = 0;
	int i = index;
	while (isdigit(str[i])) i++;

	if (i - index > 8) throw "#Index out of range";

	while (isdigit(str[index])) res = res * 10 + str[index++] - '0';
	return res;
}

/*  Compare two definishions of functions
 */
bool strcmp(string& str, int index, int element) {
	int i = 0;
	for (int size = str.length(); func[element][i] && i + index <= size; i++)
		if (func[element][i] != str[i + index]) return false;

	if (func[element][i]) return false;
	else return true;
}
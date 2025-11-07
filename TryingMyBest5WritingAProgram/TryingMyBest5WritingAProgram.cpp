// TryingMyBest5WritingAProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Token is a sequence of characters that represent something we consider a unit, such as a numeber or an operator.

#include <iostream>
#include <vector>

using namespace std;

class Token // class - means user-defined type that can encapsulate data and behavior
{
public:
	char kind;
	double value; 
	Token(char k) : kind(k), value(0.0) {} // constructor from one value
	Token(char k, double v) : kind(k), value(v) {} // constructor from two values
};

int main()
{
	// We use member access notation to access a member of an object
	// object_name . member_name

	vector<Token> tok;

	cout << "Please enter expressopm (we cn gnale +, -, *, /): \n";
	cout << "add an x to end expression (e.g., 1+2*3x)\n";

	int lval = 0;
	int rval = 0;
	cin >> lval; // read first number
	if (!cin) {
		cerr << "Error: invalid left operand\n";
		return 1;
	}

	for (char op; cin >> op; ) // read operator untill x is encountered
	{
		if (op != 'x') {
			cin >> rval; // read right operand
		}
		if (!cin) {
			cerr << "Error: invalid right operand\n";
			return 1;
		}

		switch (op) {
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			if (rval == 0) {
				cerr << "Error: division by zero\n";
				return 1;
			}
			lval /= rval;
			break;
		default: //not another operator: print result and exit
			cout << "Result: " << lval << endl;
			return 0;
		}
	}

	cerr << "Error: expression must end with 'x'\n";
	return 1;
}

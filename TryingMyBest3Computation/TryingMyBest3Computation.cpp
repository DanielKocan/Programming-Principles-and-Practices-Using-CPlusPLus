// Computation - means performing calculations or processing data according to a set of rules or instructions.
// Input -> Code (data) -> Output 
#include <iostream>
#include <vector>

int main()
{
	constexpr int max = 100; // constant expression - a value that is known at compile time and does not change during program execution
	
	int a;
	std::cin >> a;

	const int b = a; // constant - is initialized with a value that is known at compile time and never changes after initialization

	std::cout << a << " " << b << "\n";
	
	// statements - instructions that perform some action (like declaration, assignment, loops, conditionals)
	if (a == 0); // empty statement
	int c = a + b;

	// if (expression)
	//		statement // a sequence of statements delmited by {} is called a block statement or compound statement
	// else
	//		statement

	// Switch statement - you cant swtich string or float (only int, char, enum)
	// Case lebels must be constant expressions (cant be variables)
	// You can use same value for two case labels

	std::cout << "Please enter a digit\n";
	char g = 0;
	std::cin >> g;

	switch (g)
	{
	case '0': case '2': case '4': case '6': case '8':
		std::cout << "even \n";
		break;
	case '1': case '3': case '5': case '7': case '9':
		std::cout << "odd \n";
		break;
	default:
		std::cout << "not a digit \n";
		break;
	}
	// [[fallthrough]] - attribute to indicate intentional fallthrough between switch cases (C++17 feature)

	// --- VECTORS 3.6 ---

	std::vector<int> v = { 5,7,9,4,6,8 };
	//or
	std::vector<int> v2(6); // vector of size 6 with default initialized elements (0 for int)

	//we can loop vector like this:
	for (int x:v) // We reed it like that for each element int x in v: range-based for loop (C++11 feature). Equalent to [0;v.size()) - half-open sequence
	{
		std::cout << x << "\n";
	}

	v.push_back(10); // add element to the end of the vector
	// push_back - membver function call; push_back() is a member function of vector and must be called using this dot notation:
	//  object-name . member-function-name(argument-list)

	std::vector<double> temps;
	// CTRL + D to end input on Linux/Mac, CTRL + Z on Windows
	for (double temp; std::cin >> temp;) // we define a vaeriable temp of type double to read into. cin..temp, as the condtion for a for-statement. Basically, cin>>temp returns true if the input operation succeeded, false otherwise.
	{
		temps.push_back(temp);
	}

	return 0;
}


// a  function is a named sequence of statements 
// Function definition:
//  type-identifier/the-return-type function-indentifier/the-name-of-the-function ( parameter-list ) function-body/statement-to-be-executed

int square(int x) // function declaration and definition (it takes int an int argument (x) and that it returns an int)
{
	return x * x; // return statement
}

//Review
/*
	What is computation?
		Performing calculations or processing data according to a set of rules or instructions.

	What to we mean by inputs and outputs to a computation? Give examples.
		Input - data provided to the computation (e.g., user input, files, sensors)
		Output - result produced by the computation (e.g., displayed results, saved files, signals)

	What are the three requirements for a computation?
		1. Input
		2. Processing (the computation itself)
		3. Output

	What does expression do?
		Evaluates to a value.

	What is a difference between a statement and an expression?
		An expression (Wyrazenie) evaluates to a value, while a statement (instrukcja lub polecenie) performs an action.

	What is an lvalue? list the operators that require an lvalue. Why do these operators and not the others require an lvalue?
		An lvalue is an expression that refers to a memory location and allows us to take the address of that location using the address-of operator (&).
		Operators that require an lvalue include:
			- Assignment operator (=)
			- Address-of operator (&)
			- Increment (++) and decrement (--) operators
		These operators require an lvalue because they need to modify or access the memory location directly.

	What is an rvalue?
		An rvalue is an expression that represents a temporary value or a value that does not have a persistent memory location.

	What is literal? Give examples of different kinds of literals.
		A literal is a fixed value directly written in the code.
		Examples:
			- Integer literal: 42
			- Floating-point literal: 3.14
			- Character literal: 'a'
			- String literal: "Hello, World!"

*/

// Computation - means performing calculations or processing data according to a set of rules or instructions.
// Input -> Code (data) -> Output 
#include <iostream>

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
	//		statement
	// else
	//		statement
}

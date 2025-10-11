#include <iostream>

using namespace std; // This is a directive that tells the compiler to use the standard namespace.

// A TYPE defines a set of possible values and set of operation (for an object)
// An OBJECT is some memory that holds a value of a specific (given) type.
// a VALUE is a set of bits in memory intrerpreted according to a specific type.
// a VARIABLE is a named object
// a DECLARATION is a statement that gives a name and a type to an object.
// a DEFINITION is a declaration that sets aside memory for an object.

// For historically and pracital reasons C++ offers four notation for initialization:
// T a = b;
// T a{b}; 
// T a = {b};
// T a(b); 

int main()
{
    cout << "Please enter your name \n";

	string name;  // defines a variable named 'name' of type std::string (allocates memory for it)
	// to access an object we need a name. A named object is called a variable and has a specific type.
    // That determines what can be put into object and which operation can be applied to it.
    // The data items we put into variables are called VALUES.

	name = "blank"; // INITIALIZATION: the variable 'name' is initialized with the value "blank". = - assignment operator, it gives a variable a new value.
	// Initialization: giving a variable its initial (first) value. (initialization always finds the variable empty)
	// Assignment: giving a variable a new value. (assignment must clear out the old value from teh variable before putting in the new value)

    cout << "Test name is:" << name << endl;
	cout << "Please enter your first name and age \n";
	string first_name = "???";
	int age = -1; // a name for the variable must start with a letter, can be letter, digits or underscore, no spaces, no special character.
	cin >> first_name >> age;
	cout << "Hello, " << first_name << " (age " << age << ")\n";

	double d = 0;
	while (cin >> d)
	{
		int i = d;
		char c = i;
		cout << "d==" << d
			<< " i==" << i
			<< " c==" << c
			<< " char (" << c << ")\n";
	}
}
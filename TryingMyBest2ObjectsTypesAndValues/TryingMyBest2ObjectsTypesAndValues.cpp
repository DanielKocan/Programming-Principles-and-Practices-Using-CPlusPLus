#include <iostream>

using namespace std; // This is a directive that tells the compiler to use the standard namespace.

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
	int age = -1;
	cin >> first_name >> age;
	cout << "Hello, " << first_name << " (age " << age << ")\n";
}
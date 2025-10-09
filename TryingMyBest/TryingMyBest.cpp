#include <iostream>

// Every c++ program must have a main function called main

// C++ is compiled language, so it needs to be compiled before running ( translate from human readable to machine readable)
// Compiler translates the code to machine code. C++ source code -> compiler -> Object code.
int main()
{
    std::cout << "Hello World!\n";
	return 0; // Usually 0 indicates that the program ended successfully (intersting: in main and only main you dont need to write return 0, it is added automatically)
}

// There are separate parts of c++ code (sometimes called modules or translation units): they must be compiled separately and then linked together
//Source file 1 -> compiler -> Object file 1 \__
//Source file 2 -> compiler -> Object file 2  _/-> linker -> Executable file (on widnows it is often .exe)

// Library is simply code that someone else wrote, and you can use it in your program.
// TryingMyBest4Errors.cpp 

// compile-time errors - errors found by compiler before program runs
//  - Syntax errors
//  - Type errors
// Link time errors - errors found by linker when trying to create executable (combine object files into an executable file)
// Runtime errors - errors that occur while program is running
//  - Errors detected by computer (hardwawre and/or operating system)
//  - Errors detected by library (e.g. the standard library)
//  - Errors Detected by user code (they are also called Logic errors)
// Undeceted logic erros leadding rtto crash or wrong results
// Mismatches between what user need and what the code delivers

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

// ===== SYNTAX ERRORS (won't compile) =====
// 1. Missing semicolon
// int x = 5

// 2. Missing closing brace
// void func() {
//     cout << "Hello";

// 3. Wrong bracket type
// int arr[5];
// arr(0) = 10;

// 4. Missing quotes
// string name = Hello;

// 5. Typo in keyword
// intt x = 5;


// ===== TYPE ERRORS (won't compile) =====
void typeErrors() {
    // 1. Assigning string to int
    // int age = "25";

    // 2. Incompatible pointer types
    // int* ptr = new double(5.5);

    // 3. Wrong function parameter type
    // void func(int x);
    // func("hello");

    // 4. Array size must be constant
    // int n = 5;
    // int arr[n];  // error in strict C++

    // 5. Void function returning value
    // void test() { return 5; }
}


// ===== LINKER ERRORS (compiles but won't link) =====
// 1. Function declared but not defined
void undefinedFunction();

// 2. Multiple main functions (in multiple files)
// int main() {} // in file1.cpp
// int main() {} // in file2.cpp

// 3. Missing library link
// Using sqrt() without linking math library (-lm)

// 4. Duplicate function definitions
// void duplicate() { }  // in file1.cpp
// void duplicate() { }  // in file2.cpp

// 5. External variable not defined
extern int globalVar;

// ==== = LOGIC ERRORS(compiles and runs but wrong result) ==== =
void logicErrors() {
    // 1. Off-by-one error
    int arr[5] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i <= 5; i++) {  // should be i < 5
        // Accesses arr[5] which is out of bounds
    }

    // 2. Integer division instead of float
    int a = 5, b = 2;
    double result = a / b;  // result is 2.0, not 2.5
    cout << "5/2 = " << result << endl;

    // 3. Using = instead of ==
    int x = 10;
    if (x = 5) {  // assigns 5 to x, always true
        cout << "x is now: " << x << endl;
    }

    // 4. Infinite loop
    // for (int i = 10; i > 0; i++) {  // i never reaches 0
    //     cout << i << endl;
    // }

    // 5. Wrong calculation order
    int price = 100;
    int discount = 20;
    int final = price - discount / 100;  // Wrong! Should be (price - discount) / 100
    cout << "Wrong calculation: " << final << endl;
}

// Function that might throw an exception
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero!");
    }
    return numerator / denominator;
}

int main() {
    double a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try {
        double result = divide(a, b);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        // Catch specific exception and output to cerr
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const exception& e) {
        // Catch any other standard exceptions
        cerr << "Unexpected error: " << e.what() << endl;
        return 2;
    }
    catch (...) {
        // Catch any other non-standard exceptions
        cerr << "Unknown error occurred!" << endl;
        return 3;
    }

    cout << "Program completed successfully!" << endl;
    return 0;
}
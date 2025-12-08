// Main project where I try bunch of different stuff in C++

#include <iostream>

int main()
{
    int a = 5, b = 6;          // copy-initialization
    int c(7), d(8);      // direct-initialization
    int e{ 9 }, f{ 10 };     // direct-list-initialization
    int i{}, j{};            // value-initialization

    std::cout << "Hello World!\n";
}
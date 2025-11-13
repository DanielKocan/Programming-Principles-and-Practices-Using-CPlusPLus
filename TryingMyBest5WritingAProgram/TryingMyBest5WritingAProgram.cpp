// TryingMyBest5WritingAProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Token is a sequence of characters that represent something we consider a unit, such as a numeber or an operator.

#include <iostream>
#include <vector>

using namespace std;

class Token // this pattern is called tokenization or lexical analysis - it's the first step in parsing mathematical expressions or programming languages!
{
public:
    char kind;		// what kind of token
    double value;	// for numbers: a value

    // constructors
    Token(char ch) : kind{ ch }, value{ 0.0 } {}
    Token(char ch, double val) : kind{ ch }, value{ val } {}
};

class Token_stream // potok
{
public:
    // The constructor just sets full to indicate that the buffer is empty:
    Token_stream() : full{ false }, buffer{ 0 } {}
    Token get();                // this class has a member function called get that returns a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back

private:
    bool full;                  // is there a Token in the buffer?
    Token buffer;               // - A buffer is temporary storage that holds data for a short time. Here is where we keep a Token put back using putback()
};

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    // precondition check
    if (full)
    {
        cout << "putback() into full buffer";
    }
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get()
{
    // do we already have a Token ready
    if (full)
    {
        // remove token from buffer
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;  // note that >> skips whitespace (space, newline, tab, etc.)

    Token t{ 0 };
    switch (ch)
    {
    case ';':               // for "print"
    case 'q':               // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        t = { ch };         // let each character represent itself
        break;
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        /*
        ## The magic:
        - `ch` holds **one character** (`'4'`)
        - `val` holds **the full number** (`42.0`)
        - `std::cin >> val` is smart - it reads **as many digits as it can** to form a complete number
        */

        std::cin.putback(ch);     // put digit back into the input stream
        double val;
        std::cin >> val;            // read a floating-point number
        t = { '8', val };           // let '8' represent "a number"
    }
    break;
    default:
        cout << "Bad token";
    }
    return t;
}

Token_stream ts;        // provides get() and putback() 
double expression();    // declaration so that primary() can call expression()

// deal with numbers and parentheses
double primary() //The smallest building block - just a number or something in parentheses (Example: 2, 3, 4)
{
    Token t = ts.get();
    double d{};
    switch (t.kind)
    {
    case '(':           // handle '(' expression ')'
    {
        d = expression();
        t = ts.get();
        if (t.kind != ')') cout << "')' expected";
        break;
    }
    case '8':           // we use '8' to represent a number
        return t.value; // return the number's value
    default:
        cout << "primary expected";
    }
    return d;
}

// deal with *, /, and %
double term() // Term - One "piece" of the expression (Example: 2 and 3 * 4)
{
    double left = primary();
    Token t = ts.get();            // get the next token from token stream

    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) cout << "divide by zero";
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);    // put t back into the token stream
            return left;
        }
    }
}

// deal with + and -
double expression() // Expression - The whole calculation (Example:  2 + 3 * 4)
{
    double left = term();           // read and evaluate a Term
    Token t = ts.get();             // get the next token from token stream

    while (true) // Loop forever... BUT we have a way out!
    {
        switch (t.kind)
        {
        case '+':
            left += term();     // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();     // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);    // put t back into the token stream
            // EXIT THE LOOP AND FUNCTION!
            return left;        // finally: no more + or -: return the answer. 
        }
    }
}

//------------------------------------------------------------------------------

// We use member access notation to access a member of an object
// object_name . member_name
int main()
try
{
    double val{ 0.0 };
    while (std::cin) //  fails when the stream enters an error state or reaches end of input.It fails when: User presses Ctrl+D (Linux/Mac) or Ctrl+Z (Windows), Reading from a file and you reach the end, Bad input - trying to read data that doesn't match what you're expecting (   int x; std::cin >> x;  // user types "hello" instead of a number)
    {
        auto t = ts.get();
        if (t.kind == 'q')         // 'q' for quit
        {
            break;
        }
        if (t.kind == ';')         // ';' for "print now"
        {
            std::cout << "=" << val << '\n';
        }
        else
        {
            ts.putback(t);
            val = expression();
        }
    }
    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "exception \n";
    return 2;
}
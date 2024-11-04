#include <iostream>
using namespace std;  //Simplify cin, cout and endl use
int main()
{
	cout << "Please enter your first name (followed " << "by 'enter'):" << endl;
	string first_name;
	// read first name:
	cin >> first_name;
	cout << "Hello, " << first_name << endl;
}

// note how several values can be output by a single statement
// a statement that introduces a variable is called a declaration
// a variable holds a value of a specified type
// the final return 0; is optional in main()
// but you may need to include it to pacify your compiler

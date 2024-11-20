#include <iostream>
#include <stack>

using namespace std;

int main(){

stack<int> intStack; // empty stack
// fill up the stack
for (size_t ix = 0; ix != 10; ++ix) 
	intStack.push(ix); // intStackholds 0 ... 9 inclusive

while (!intStack.empty()) { // while there are still values in 
	 		         // intStack 
	int value = intStack.top(); 
	// code that uses value 
	cout << value <<" ";
	intStack.pop(); // pop the top element, and repeat 
} 

cout << endl;

return 0;

}

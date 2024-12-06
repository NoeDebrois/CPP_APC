#include <iostream> 
int main( int argc, char *argv[] ) 
{ 
	if( argc == 2 ) { 
		std::cout << "The argument supplied is " << 
				argv[1] << std::endl; 
	} 
	else if( argc > 2 ) 
	{ 
		 std::cout << "Too many arguments supplied." << std::endl; 	
	} 
	else 
		 std::cout << "One argument expected." << std::endl; 
}


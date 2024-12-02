#include <iostream>

#include "Sales_data.h"

// LECTURE 8 - Constructors :
// Here, we show the utility of defining different constructors (so that we control what happens,
// depending on the number of arguments we enter when calling the constructor).
// Here is an example with 3 different constructors : one for when we don't give any argument,
// one with one argument and a last one with the full 3 arguments.
// Note that, for example, the one with no argument calls the one with the full 3 arguments in a
// certain way that WE control, i.e, with book number = "", units sold = 0, and revenue = 0.
//

int  main() {

  std::cout << "This is s1"<<std::endl;
  Sales_data s1("01",1,5);
  s1.print();

    std::cout << "----------------------------------------" << std::endl;
  std::cout << "This is s2"<<std::endl;
  Sales_data s2("02");
  s2.print();

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "This is s3"<<std::endl;
  Sales_data s3;
  s3.print();
}

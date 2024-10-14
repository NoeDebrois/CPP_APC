#include "Book.h"
#include "Library.h"

//
// Exercise session 2 : book library
// Goal :
// - Design and implement a Library Service
// - You are provided with the structure of the  2 main classes of your application : Book & Library
//      - Book : stores book details and provides basic access to data
//      - Library : stores all books and implements the Library service operations (e.g rent, return...)
//


using std::cout;
using std::endl;

int main()
{
  Book b1(
      1,
      2013,
      1399,
      "S. B. Lippman",
      "C++ primer");

  Book b2(
      2,
      2013,
      1361,
      "B. Stroustrup",
      "The C++ programming language");

  b1.print();
  b2.print();


  Library lib;

  lib.add_book(b1);
  lib.add_book(b2);

  lib.rent_book("S. B. Lippman", "C++ primer");
  lib.print();
  cout << "****************+"<< endl;

  lib.rent_book("S. B. Lippman", "C++ primer");
  lib.print();
  cout << "****************+"<< endl;

  lib.return_book(1);
  lib.print();
  cout << "****************+"<< endl;

  lib.return_book(1);
  lib.print();
  cout << "****************+"<< endl;

  cout << "Oldest book" << endl;
  lib.print_oldest();

  return 0;
}
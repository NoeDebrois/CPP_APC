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
  // Let's create two books :
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

  // Let's print the two books that we created :
  cout << "Let's print the two books that we created :\n" << endl;
  std::cout << "-- Book 1 --" << std::endl;
  b1.print();
  std::cout << "\n-- Book 2 --" << std::endl;
  b2.print();
  std::cout << "\n" << std::endl;
  cout << "\n****************+"<< endl;

  // Let's create a library :
  Library lib;

  // Let's add our two books to our library :
  lib.add_book(b1);
  lib.add_book(b2);

  // Let's rent book b1 :
  cout << "Let's rent book b1 and print our updated library :\n" << endl;
  lib.rent_book("S. B. Lippman", "C++ primer");
  lib.print();
  cout << "\n****************+"<< endl;

  std::cout << "\n" << endl;

  // Let's try to rent book b1 AGAIN (it is already rented!) :
  cout << "Let's try to rent book b1 AGAIN (it is already rented!) : \n" << endl;
  lib.rent_book("S. B. Lippman", "C++ primer");
  lib.print();
  cout << "\n****************+"<< endl;

  std::cout << "\n" << endl;

  // Let's return book b1 :
  cout << "Let's return book b1 : \n" << endl;
  lib.return_book(1);
  lib.print();
  cout << "\n****************+"<< endl;

  std::cout << "\n" << endl;

  // Let's return book b1 ONCE AGAIN (it was already returned) :
  cout << "Let's return book b1 ONCE AGAIN (it was already returned) :\n " << endl;
  lib.return_book(1);
  lib.print();
  cout << "\n****************+"<< endl;

  std::cout << "\n" << endl;

  // Print the oldest book from the library :
  cout << "Let's print the oldest book from the library : \n" << endl;
  cout << "Oldest book" << endl;
  lib.print_oldest();

  return 0;
}
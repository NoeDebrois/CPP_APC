#include <iostream>
#include <set>

#include "Sales_data.h"

int  main() {

  //std::cout << "This is s1"<<std::endl;
  Sales_data s1("01",1,5);
  //s1.print();


  //std::cout << "This is s2"<<std::endl;
  Sales_data s2("02");

  //s2.print();

  //std::cout << "This is s3"<<std::endl;
  Sales_data s3;
  //s3.print();


  std::multiset<Sales_data> bookstore; // rely on operator < definition

  bookstore.insert(s1);
  bookstore.insert(s2);
  bookstore.insert(s3);

  for (const  Sales_data & sd : bookstore)
    sd.print();

  return 0;
}

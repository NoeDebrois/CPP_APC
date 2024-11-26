#include <iostream>
#include <unordered_map>
#include <string>

#include "Sales_data.h"

using std::string;

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

                                                                                            // number of buckets and hash function
  std::unordered_map<string, Sales_data> bookstore ;

  bookstore.insert(std::make_pair(s1.isbn(),  s1));
  bookstore.insert(std::make_pair(s2.isbn(),  s2));
  bookstore.insert(std::make_pair(s3.isbn(),  s3));

  for (const auto & sd : bookstore)
    sd.second.print();

  return 0;
}

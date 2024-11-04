#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
public:
	// non-delegating constructor initializes members from
	// corresponding arguments
	Sales_data(const std::string& s, unsigned cnt, double price);

  // remaining constructors all delegate to another constructor
	Sales_data();

  Sales_data(const std::string& s);

  /* Implement as homework
  Sales_data(std::istream &is): Sales_data()
		 			{ read(is, *this); }*/

  // other members as before, complete as homework

  std::string isbn() const { return bookNo; }

  void print () const;

private:
  std::string bookNo ;
  unsigned units_sold ;
  double revenue ;

};

#endif

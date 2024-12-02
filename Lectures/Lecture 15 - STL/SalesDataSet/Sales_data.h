#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data {
public:
	// non-delegating constructor initializes members from
	// corresponding arguments
	Sales_data(std::string s, unsigned cnt, double price):
	bookNo(s), units_sold(cnt), revenue(cnt*price)
      {}
			   // remaining constructors all
	       // delegate to another constructor
	Sales_data() : Sales_data("", 0, 0) {}

  Sales_data(std::string s): Sales_data(s, 0,0) {}




  std::string isbn() const { return bookNo; }

  void print () const;

private:
  std::string bookNo ;
  unsigned units_sold = 0 ;
  double revenue = 0 ;

};

bool operator < (const Sales_data & lhs, const Sales_data & rhs);




#endif // SALES_DATA_H

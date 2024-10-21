#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data {

public:

  std::string isbn() const { return bookNo; }

	Sales_data & operator+=(const Sales_data & rhs);
  Sales_data operator+(const Sales_data & rhs) const;
  void print () const;

	void set_isbn(const std::string & bn){ bookNo = bn; }
	void set_units_sold(unsigned u_sold) { units_sold = u_sold; }
  void set_revenue(double rv){ revenue = rv; }

private:
	std::string bookNo ;
	unsigned units_sold = 0;
	double revenue = 0.0;

};



#endif

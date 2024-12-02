#include "Sales_data.h"


// Lipmann's implementation is more general, have a look to the book !!
void Sales_data::print () const{

  std::cout << "ISBN: " << bookNo << " unit solds: " << units_sold
            << " revenue: " << revenue <<std::endl;

}

Sales_data & Sales_data::operator+=(const Sales_data & rhs){
  units_sold += rhs.units_sold; // add the members of rhs into
	revenue += rhs.revenue; // the members of ''this'' object
	return *this; // return the object on which the function was
		            // called
}

Sales_data Sales_data::operator+(const Sales_data & rhs) const{
  Sales_data sum = *this;    // copy data member from object to sum
	sum+=rhs; 	// add data member from rhs into sum
	return sum;
}

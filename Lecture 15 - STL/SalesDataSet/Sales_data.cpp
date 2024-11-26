#include "Sales_data.h"


// Lipmann's implementation is more general, have a look to the book !!
void Sales_data::print () const{

  std::cout << "ISBN: " << bookNo << " unit solds: " << units_sold
            << " revenue: " << revenue <<std::endl;

}


bool operator < (const Sales_data &lhs, const Sales_data &rhs){

		return lhs.isbn() < rhs.isbn();

}

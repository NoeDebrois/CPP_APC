#include "Sales_data.h"

void Sales_data::print () const{

  std::cout << "ISBN: " << bookNo << " unit solds: " << units_sold
            << " revenue: " << revenue <<std::endl;

}


#include "Sales_data.h"

Sales_data::Sales_data(const std::string& s, unsigned cnt, double price):
  bookNo(s), units_sold(cnt), revenue(cnt*price)
{
    std::cout << "3 parameters version\n"; 
}

Sales_data::Sales_data(): Sales_data("", 0, 0) 
{
    std::cout << "Default version\n"; 
}

Sales_data::Sales_data(const std::string& s): Sales_data(s, 0,0) 
{ 
    std::cout << "1 parameter version\n"; 
}

// Lipmann's implementation is more general, have a look to the book !!
void Sales_data::print () const
{
  std::cout << "ISBN: " << bookNo << " / unit solds: " << units_sold
            << " / revenue: " << revenue << std::endl;
}

#include <iostream>

#include "Sales_data.h"

int  main() {

  Sales_data s1;
  s1.set_isbn("01");
  s1.set_revenue(100);
  s1.set_units_sold(1);

  s1.print();


  Sales_data s2;
  s2.set_isbn("01");
  s2.set_revenue(180);
  s2.set_units_sold(2);

  s2.print();
  Sales_data s3 = s1 + s2;

  s3.print();

  return 0;
}

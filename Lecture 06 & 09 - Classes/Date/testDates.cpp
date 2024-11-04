#include <iostream>
#include "Date.h"

using namespace std;

int main(){

Date d(2011,1,1);
Date my_birthday {1950, 12, 30};

d.print();
my_birthday.print();
cout << endl;

cout << "d.month() gives : " << d.month() << endl; // Call the month() method on d
cout << endl;

cout << "Before add_day() method : " << endl;
d.print();
d.add_day(4); // Call the add_day() method on d
cout << "After add_day() method : " << endl;
d.print(); // Check that the add_day() method worked
}

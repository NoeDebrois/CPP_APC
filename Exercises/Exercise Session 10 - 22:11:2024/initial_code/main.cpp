#include "Calendar.h"

using std::cout;
using std::endl;

int main() 
{
    Calendar c0;
    Event e0(time(0), "Important Meeting");
    c0.addEvent(e0);

    Calendar c1;
    Event e1(time(0), "Andrew's Birthday");
    c1.addEvent(e1);
    c1 = c0;

    Calendar c2(c0);
    Event e2(time(0), "Trip to Cairo");
    c2.addEvent(e2);

    c2 = Calendar();
    Event e3(time(0), "Visit to Museum");
    c2.addEvent(e3);

    cout << "c0:" << endl;
    c0.print();
    cout << "c1:" << endl;
    c1.print();
    cout << "c2:" << endl;
    c2.print();

    c1.updateEvent(time(0), "Important Meeting", time(0), "Ride a camel");

    cout << endl;
    cout << "c0:" << endl;
    c0.print();
    cout << "c1:" << endl;
    c1.print();
    cout << "c2:" << endl;
    c2.print();

    return 0;
}

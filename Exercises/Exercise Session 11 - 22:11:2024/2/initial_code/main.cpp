#include "Schedule.h"

using std::cout;
using std::endl;

int main()
{
    //Job(id_type j_id, time_instant sub_time, time_instant exe_time, time_instant dline, double w =1.0):
    std::shared_ptr<Job> j1 = std::make_shared<Job> (0, 0, 1, 1, 2.0);
    std::shared_ptr<Job> j2 = std::make_shared<Job> (1, 0, 2, 2, 3.0);
    std::shared_ptr<Job> j3 = std::make_shared<Job> (2, 10, 4, 4);

    j1->print();
    cout << endl;
    j2->print();
    cout << endl;
    j3->print();
    cout << "\n" << endl;

    Schedule s;
    s.add(j3);
    s.add(j2);
    s.add(j1);
    s.print();

    cout << "Total: " << s.evaluate() << "\n" << endl;

    return 0;
}

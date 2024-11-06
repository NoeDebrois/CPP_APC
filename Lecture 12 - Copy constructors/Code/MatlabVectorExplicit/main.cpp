#include <iostream>
#include "MatlabVector.h"

using std::cout;
using std::endl;

int main() {
    MatlabVector v;
    v[0] = 1;
    v[1] = 3;
    cout << "v content" << endl;
    v.print();
    v[3] = 4;
    cout << "v content" << endl;
    v.print();

    double d = v[4];
    cout << "v content" << endl;
    v.print();

    for (unsigned i = 0; i < v.size(); ++i)
    {
        v[i] = i;
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "v content" << endl;
    v.print();

    MatlabVector v2 = v * 3; // unfortunately 3*v does not work
    cout << "v2 content" << endl;
    v2.print();
    MatlabVector v3 = v + v2;
    cout << "v3 content" << endl;
    v3.print();

    MatlabVector v4(10);
    cout << "v4 content" << endl;
    v4.print();

    for (unsigned j = 0; j < v4.size(); ++j)
        v4[j] = j;

    // v4 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    cout << "v4 new content" << endl;
    v4.print();

    MatlabVector v5 = v4 + 3;
    //MatlabVector v5a = v4 + MatlabVector(3);
    cout << "v5 content" << endl;
    v5.print();

    MatlabVector v6 = v4 + 10;  // MatlabVector v6 = v4 + MatlabVector(10);
    cout << "v6 content" << endl;
    v6.print();

    return 0;
}

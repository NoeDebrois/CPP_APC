//
// Created by Danilo Ardagna on 14/10/21.
//

#include "My_vector.h"
using std::vector;
using std::cout;
using std::max;

int My_vector::largest_buggy()	// largest is in class scope
{
    vector<int> v;			// redeclare v, content is lost
    int r = 0;	    			// r is local
    for (int i = 0; i<v.size(); ++i) // i is in statement scope
        r = max(r,abs(v[i]));
    // no i here
    return r;
}
// no r here
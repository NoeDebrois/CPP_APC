//
// Created by Federica Filippini on 02/11/2020.
//

#include "StrLPVector.h"

using std::make_shared;
using std::vector;
using std::string;

// constructors
StrLPVector::StrLPVector (void): data(make_shared<vector<string>>()) {}

StrLPVector::StrLPVector (std::initializer_list<std::string> il):
    data(make_shared<vector<string>>(il)) {}
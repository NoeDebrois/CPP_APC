//
// Created by Danilo Ardagna on 14/07/2020.
//

#include "Author.h"

Author::Author(const string &_name, const string &_nation) : name(_name), nation(_nation) {}

string Author::get_name() const {
    return name;
}

string Author::get_nation() const {
    return nation;
}
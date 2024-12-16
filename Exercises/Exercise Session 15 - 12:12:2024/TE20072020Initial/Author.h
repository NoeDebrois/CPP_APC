//
// Created by Danilo Ardagna on 14/07/2020.
//

#ifndef AUTHORSSEARCH_AUTHOR_H
#define AUTHORSSEARCH_AUTHOR_H

#include <string>
using std::string;

class Author {
    string name;
    string nation;
public:
    Author(const string &name, const string &nation);

    string get_name() const;

    string get_nation() const;
};




#endif //AUTHORSSEARCH_AUTHOR_H

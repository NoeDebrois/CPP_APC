//
// Created by Federica Filippini on 02/11/2020.
//

#ifndef STRLPVECTORS_STRLPVECTOR_H
#define STRLPVECTORS_STRLPVECTOR_H

#include <string>
#include <vector>
#include <memory>

class StrLPVector {

public:
    typedef std::vector<std::string>::size_type size_type;

    // constructors
    StrLPVector (void);
    StrLPVector (std::initializer_list<std::string> il);

    size_type size (void) const {return data->size();}
    bool empty (void) const {return data->empty();}

    // add and remove elements
    void push_back (const std::string &t) {data->push_back(t);}
    void pop_back (void) {data->pop_back();}

    // element access
    std::string& front() {return data->front();}
    std::string& back() {return data->back();}

private:
    std::shared_ptr<std::vector<std::string>> data;

};


#endif //STRLPVECTORS_STRLPVECTOR_H

//
// Created by Danilo Ardagna on 09/10/2020.
//

#include "X.h"

int X::getMember() const {
    return member;
}

void X::setMember(int member) {
    this->member = member;
}

X::X(int member){
    this->member = member;
}

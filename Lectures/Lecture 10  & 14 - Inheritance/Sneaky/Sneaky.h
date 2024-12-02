//
// Created by Danilo Ardagna on 19/10/2019.
// Modified by Noé Debrois on 22/10/2024.
//

#ifndef SNEAKY_SNEAKY_H
#define SNEAKY_SNEAKY_H

#include "Base.h"


class Sneaky : public Base {
    void clobber1(Sneaky&); // can access Sneaky::prot_mem
    void clobber2(Base&);   // can't access Base::prot_mem
    int j; 		            // j is private by default
};


#endif //SNEAKY_SNEAKY_H
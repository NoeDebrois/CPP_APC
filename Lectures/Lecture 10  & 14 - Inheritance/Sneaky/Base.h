//
// Created by Danilo Ardagna on 19/10/2019.
// Modified by Noé Debrois on 22/20/2024.
//

#ifndef SNEAKY_BASE_H
#define SNEAKY_BASE_H


class Base {
protected: // PROTECTED IS HERE : let's see how we can access that.
    int prot_mem = 0;
public:
    int getProtMem() const;
    void setProtMem(int protMem);
    // protected member
};


#endif //SNEAKY_BASE_H
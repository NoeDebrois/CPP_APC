//
// Created by Danilo Ardagna on 19/10/2019.
// Modified by Noé Debrois on 22/10/2024.
//

#include "Sneaky.h"

// SCRIPT TO UNDERSTAND WHEN PROTECTED MEMBERS ARE ACCESSIBLE & WHEN THEY ARE NOT.

// OK : clobber1 can access the private and protected members in Sneaky objects :
// -> it's normal since protected members (from initial class, here : Base) are accessible to methods of classes (like Sneaky)
// derived from an initial class (here: Base).
// Here : prot_mem is a protected member function from Base class (the class from which Sneaky is derived) ;
// And clobber 1 is a method from Sneaky class, which is a class derived from Base class.
void Sneaky::clobber1(Sneaky &s) { s.j = s.prot_mem = 0; }

// ERROR : clobber can't access the protected members in Basevoid.
// -> it's normal since protected members are inaccessible to users of the (initial) class (objects of this class),
// like private members.
// Here : prot_mem is a protected member from Base class, and clobber2 takes as argument a Base object, thus
// we cannot access prot_mem on this base object.
void Sneaky::clobber2(Base &b) { b.prot_mem = 0; }
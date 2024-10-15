//
// Created by Noé Debrois on 15/10/2024.
//

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    // Constructor :
    Complex(unsigned int R, unsigned int I):
    RealPart(R), ImaginaryPart(I)
    {}

    // Getters :
    unsigned int getRealPart() const;
    unsigned int getImaginaryPart() const;

    // Setters :

    // Other methods :
    void print() const;
    void print_polar() const;
    double modulus() const;
    double phase() const;


    // Operator overloading :
    Complex operator+(const Complex& RHS) const;
    Complex operator-(const Complex& RHS) const;
    Complex operator*(const Complex& RHS) const;
    Complex operator/(const Complex& RHS) const;

private:
    unsigned int RealPart;
    unsigned int ImaginaryPart;
};

#endif //COMPLEX_H

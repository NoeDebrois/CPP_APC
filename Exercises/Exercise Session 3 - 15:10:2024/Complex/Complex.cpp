//
// Created by Noé Debrois on 15/10/2024.
//

#include "Complex.h"

// Getters :
unsigned int Complex::getRealPart() const {
    return RealPart;
}

unsigned int Complex::getImaginaryPart() const {
    return ImaginaryPart;
}

// Setters :

// Other methods :
void Complex::print() const {
    std::cout << RealPart << " + " << ImaginaryPart << "i " << "\n" << std::endl;
}

void Complex::print_polar() const {
    double Mod = modulus();
    double Pha = phase();
    std::cout << Mod << " * [ cos(" << Pha << ") + i * sin(" << Pha << ") ]" << "\n" << std::endl;
}

double Complex::modulus() const {
    return sqrt(RealPart * RealPart + ImaginaryPart * ImaginaryPart);
}

double Complex::phase() const {
    //
    // WARNING :
    // static_cast<double> to ensure that the division between ImaginaryPart and RealPart is handled
    // as floating-point division, since we are using unsigned int types, which would otherwise result
    // in integer division.
    //
    if (RealPart > 0) {
        return atan(static_cast<double>(ImaginaryPart) / RealPart);
    }
    else if (RealPart < 0 && ImaginaryPart >= 0) {
        return atan(static_cast<double>(ImaginaryPart) / RealPart) + M_PI;
    }
    else if (RealPart < 0 && ImaginaryPart < 0) {
        return atan(static_cast<double>(ImaginaryPart) / RealPart) - M_PI;
    }
    else if (RealPart == 0 && ImaginaryPart > 0) {
        return M_PI / 2;
    }
    else if (RealPart == 0 && ImaginaryPart < 0) {
        return - M_PI / 2;
    }
    else {
        std::cerr << "Error in the computation of the phase" << std::endl;
        return -1; // ERROR
    }
}

// Operator overloading :
Complex Complex::operator+(const Complex& rhs) const {
    return Complex(this->RealPart + rhs.getRealPart(), this->ImaginaryPart + rhs.getImaginaryPart());
}

Complex Complex::operator-(const Complex& rhs) const {
    return Complex(this->RealPart - rhs.getRealPart(), this->ImaginaryPart - rhs.getImaginaryPart());
}

Complex Complex::operator*(const Complex& rhs) const {
    return Complex(this->RealPart * rhs.getRealPart() - this->ImaginaryPart * rhs.getImaginaryPart(), this->ImaginaryPart * rhs.getRealPart() + this->RealPart * rhs.getImaginaryPart());
}

Complex Complex::operator/(const Complex& rhs) const {
    unsigned int denominator = rhs.getRealPart() * rhs.getRealPart() + rhs.getImaginaryPart() * rhs.getImaginaryPart();
    return Complex((this->RealPart * rhs.getRealPart() + this->ImaginaryPart * rhs.getImaginaryPart()) / denominator, (this->ImaginaryPart * rhs.getRealPart() - this->RealPart * rhs.getImaginaryPart()) / denominator);
}
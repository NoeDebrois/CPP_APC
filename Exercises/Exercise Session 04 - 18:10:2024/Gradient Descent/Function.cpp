/*
 * Function.cpp
 *
 *  Created on: Oct 18, 2024
 *      Author: Noé Debrois
 */

#include <cmath>

#include "Function.hpp"

// Evaluates the value of the function at a certain x.
double Function::eval (double x) const
{
    double sum = 0;
    int pow = 0;
    for (double a : coefficients)
        // Here I suppose that coefficients[0] is a_0, ..., coefficients[i] = a_i.
        sum += a * std::pow(x, pow++); // pow++ : I use the current value in pow AND THEN I increment it by 1.
    return sum;
}

// f(x) = a_0 + a_1*x + a_2*x^2 + ... + a_n*x^n -> f'(x) = 1*a_1 + 2*a_2*x + 3*a_3*x^2 + ... + n*a_n*{n-1}.
// In vectors, it means : [a_0, a_1, a_2, a_3, ..., a_n] -> [a_1, 2*a_2, 3*a_3, 4*a_4, ..., n*a_n].
Function Function::derivative() const
{
    std::vector<double> dcoeffs;
    for (size_t i = 1; i < coefficients.size(); ++i)
        dcoeffs.push_back(coefficients[i] * i);
    return Function(dcoeffs);
}

// Prints in the form : 1x^0 + 1x^1 + 2x^2 + -10x^3 + 2x^4.
void Function::print() const
{
    int pow = 0;
    for (double a : coefficients)
        if (pow == coefficients.size() - 1) {
            std::cout << a << "x^" << pow << std::endl; // To avoid a  "+" alone at the end.
        }
        else {
            std::cout << a << "x^" << pow++ << " + ";
        }
}

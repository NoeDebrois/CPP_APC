//
// Created by Danilo Ardagna on 02/06/22.
//

#include "Tensor.h"
#include <iostream>
#include <cmath>
#include <limits>

Tensor::Tensor(const index_type& dim) : dimensions(dim) {
    /* Your code goes here*/

}


double Tensor::get(unsigned int i, int j, int k) const {
    /* Your code goes here*/

}

void Tensor::set(double value, unsigned int i, int j, int k) {
    /* Your code goes here*/
}

Tensor Tensor::operator*(double alpha) const {
    /* Your code goes here*/
}
    /* compute tensor norm.
     * norm_type can be "inf", "euclidean", "2" (same as euclidean), "fro"
     * Note that "fro" can be applied only if the tensor is a bi-dimensional matrix
     * */
double Tensor::norm(const std::string& norm_type) const {

        /* Your code goes here*/
}


void Tensor::print() const {

    /* Your code goes here*/


}



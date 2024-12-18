//
// Created by Danilo Ardagna on 02/06/22.
//

#include "Tensor.h"
#include <iostream>
#include <cmath>
#include <limits>

Tensor::Tensor(const index_type& dim) : dimensions(dim) {
    if(dim.size() == 0)
      std::cerr << "ERROR: Dimensions must be non-zero." << std::endl;

}


double Tensor::get(unsigned int i, int j, int k) const {
    /* Your code goes here*/
    if (! check_indexes(i, j, k)){
      std::cerr << "ERROR: Index out of bounds." << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }
    else{
      index_type index = compute_index(i, j, k);
      auto cit = values.find(index);
      if(cit == values.end()){
        std::cerr << "ERROR: Index out of bounds." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
      }
      else
        return cit->second;
    }

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

    if (norm_type == "inf")
        return infinity_norm();
    else if (norm_type == "euclidean" or norm_type == "2" )
        return euclidean_norm();
    else if (norm_type == "fro"){
        if(dimensions.size()==2)
            return euclidean_norm();
        else
            std::cerr << "Frobenius norm can be computed only for matrices" << std::endl;
    }
    else{
        std::cerr << "Unknown norm" << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }

    return std::numeric_limits<double>::quiet_NaN();
}


void Tensor::print() const {

    /* Your code goes here*/


}



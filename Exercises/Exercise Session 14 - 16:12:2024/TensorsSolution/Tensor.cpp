//
// Created by Danilo Ardagna on 02/06/22.
//

#include "Tensor.h"
#include <iostream>
#include <cmath>
#include <limits>

Tensor::Tensor(const index_type& dim) : dimensions(dim) {
    if (dim.size()==0)
        std::cerr << "0 dimensional Tensor created. FATAL ERROR" << std::endl;

}

double Tensor::infinity_norm() const {
    double norm = -1;

    for (auto cit = values.cbegin(); cit != values.cend();++cit)
        if (abs(cit->second) > norm)
            norm = abs(cit->second);

    return norm;
}

double Tensor::euclidean_norm() const {
    double norm = 0;

    for (auto cit = values.cbegin(); cit != values.cend();++cit)
        norm += cit->second * cit->second;

    return sqrt(norm);
}


double Tensor::get(unsigned int i, int j, int k) const {
    if (!check_indexes(i, j, k)) {
        std::cerr << "Index not appropriate" << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }
    else{
        index_type indexes = compute_index(i, j, k);
        if (values.find(indexes)!=values.cend())
            return values.at(indexes);
        else{
            std::cerr << "Index not appropriate" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }


    }

}

void Tensor::set(double value, unsigned int i, int j, int k) {
    if (!check_indexes(i, j, k)) {
        std::cerr << "Index not appropriate" << std::endl;
    }
    else{
        index_type indexes = compute_index(i, j, k);
        values[indexes] = value;

    }
}

Tensor Tensor::operator*(double alpha) const {
    Tensor result(dimensions);
    for (auto cit = values.cbegin(); cit != values.cend();++cit)
        result.values[cit->first]= alpha* cit->second;

    return result;
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

bool Tensor::check_indexes(unsigned int i, int j, int k) const{

    if (dimensions.size()==0)
        return false;

    if (i>= dimensions[0])
        return false;

    // first check if index is used and dimensions are not appropriate
    // then check if dimensions are such that dimensions[1] can be accessed and j is out of bound
    if ((j>=0 and dimensions.size()==1) or (dimensions.size()>1 and j>= dimensions[1]))
            return false;

    if ((k>=0 and dimensions.size()<=2) or (dimensions.size()>2 and k>= dimensions[2]))
        return false;

    // If we reach the code here the index is appropriate
    return true;


}

Tensor::index_type Tensor::compute_index(unsigned int i, int j, int k) const {
    index_type new_index(dimensions.size());
    new_index[0] = i;
    if (j>=0)
        new_index[1]=j;
    if (k>=0)
        new_index[2]=k;

    return new_index;
}

void Tensor::print() const {

    for (auto cit = values.cbegin(); cit != values.cend();++cit){
        // print index
        for (auto index_coord : cit->first)
            std::cout << index_coord << " ";
        std::cout <<  " : ";
        // print value
        std::cout << cit->second << std::endl;
    }


}



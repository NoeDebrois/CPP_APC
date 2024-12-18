//
// Created by Danilo Ardagna on 02/06/22.
//

#ifndef TENSORS_TENSOR_H
#define TENSORS_TENSOR_H

#include <vector>
#include <map>
#include <cmath>
#include <string>

class Tensor {
public:

    typedef std::vector<unsigned> index_type;

private:
    index_type dimensions;
    std::map<index_type, double> values;

    /* Your code goes here*/
    bool check_indexes(unsigned i, int j, int k) const;

    index_type compute_index(unsigned i, int j, int k) const;

    double infinity_norm() const;
    double euclidean_norm() const;

public:


    Tensor(const index_type &dimensions);

    void reshape(index_type new_shape);

    double get(unsigned i, int j=-1, int k= -1) const;

    void set(double value, unsigned i, int j=-1, int k= -1);

    Tensor operator*(double alpha) const;

    /* compute tensor norm.
     * norm_type can be "inf", "euclidean", "2" (same as euclidean), "fro"
     * Note that "fro" can be applied only if the tensor is a bi-dimensional matrix
     * */
    double norm(const std::string& norm_type) const;

    void print() const;

};


inline bool Tensor::check_indexes(unsigned i, int j, int k) const {

    if (dimensions.size()== 0)
        return false;

    if (i >= dimensions[0])
        return false;

    if ((j>=0 and dimensions.size()==1) or (dimensions.size() >1 and j >= dimensions[1]))
        return false;

    if ((k>=0 and dimensions.size()<=2) or (dimensions.size()>2 and k>= dimensions[2]))
        return false;

    return true;

}

inline Tensor::index_type Tensor::compute_index(unsigned i, int j, int k) const {

    index_type new_index(dimensions.size());
    new_index[0] = i;
    if (j>=0)
        new_index[1]=j;
    if (k>=0)
        new_index[2]=k;

    return new_index;

}

inline double Tensor::euclidean_norm() const {
    double norm = 0.0;
    /*
    for (auto cit = values.cbegin(); cit != values.cend(); ++cit)
        norm += (*cit).second * (*cit).second;*/

    for (const auto &[k, v] : values)
        norm += v*v;

    return sqrt(norm);
}
#endif //TENSORS_TENSOR_H

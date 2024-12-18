//
// Created by Danilo Ardagna on 02/06/22.
//

#ifndef TENSORS_TENSOR_H
#define TENSORS_TENSOR_H

#include <vector>
#include <map>
#include <string>

class Tensor {
public:

    typedef std::vector<unsigned> index_type;

private:
    std::vector<unsigned> dimensions;
    std::map<index_type, double> values;

    double infinity_norm() const;

    double euclidean_norm() const;

    bool check_indexes(unsigned i, int j, int k) const;

    index_type compute_index(unsigned i, int j, int k) const;

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


#endif //TENSORS_TENSOR_H

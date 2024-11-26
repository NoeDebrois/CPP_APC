#ifndef CONVNET_MATRIX_HPP
#define CONVNET_MATRIX_HPP

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

namespace convnet {

// This is a simplified implementation of a matrix, providing only the essential features
// to store weights for Fully-Connected (FC) layers
    class matrix {

    private:
        std::size_t n_rows, n_cols;
        std::vector<double> values;

    public :
        matrix() {
            n_rows = 0;
            n_cols = 0;
        };

        matrix(std::size_t nrs, std::size_t ncs);

        void print() const;

        matrix &operator*=(double x);

        matrix &operator-=(const matrix &other_matrix);

        void initialize_with_zeros();

        void initialize_with_random_normal(double mean, double variance);

        // matrix-vector multiplication
        std::vector<double> dot(const std::vector<double> &other_vector) const;

        // Determine the dot product between the transpose of this matrix and a
        // vector, without storing the transpose
        std::vector<double> Tdot(const std::vector<double> &other_vector) const;

        size_t get_n_rows() const;

        size_t get_n_cols() const;

        const std::vector<double> &get_values() const;

        void set_values(const std::vector<double> &vs);

    }; // matrix

} // namespace
#endif

#ifndef CONVNET_TENSOR_3D_HPP
#define CONVNET_TENSOR_3D_HPP

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <assert.h>

namespace convnet {

// A lightweight implementation of a 3D array designed to provide essential functionality.
// Suitable for storing image data and convolutional layer filter weights.
    class tensor_3d {

    private:
        std::size_t height, width, depth;
        std::vector<double> values;
    public:
        // CONSTRUCTORS :
        // - With the 3 dimensions :
        tensor_3d(std::size_t h, std::size_t w, std::size_t d);
        // - With nothing :
        tensor_3d();
        // - With a reference to another tensor_3d :
        tensor_3d(const tensor_3d &T);
        // - With the 3 dimensions and all the values :
        tensor_3d(std::size_t h, std::size_t w, std::size_t d, std::vector<double> _values);

        tensor_3d operator=(const tensor_3d &T) {
            height = T.height;
            width = T.width;
            depth = T.depth;
            values = T.values;
            return *this;
        };

        // Uses reserve (both) :
        void initialize_with_random_normal(double mean, double variance);
        void initialize_with_zeros();
        //

        // The 2 needed versions of the operator() to access & to modify values a in tensor_3d :
        // Constant version of the operator() to access values in a tensor_3d.
        inline double operator()(std::size_t i, std::size_t j, std::size_t k) const {
            // Calculate the index for the 1D array (values) based on the 3D coordinates (i, j, k)
            // Formula: (height * width * k) gives the offset for the k-th "layer"
            // width * i gives the row offset within that "layer"
            // j gives the column offset within the row
            return values[height * width * k + width * i + j];
        };
        // Non-constant version of the operator() to modify values in a tensor_3d.
        inline double &operator()(std::size_t i, std::size_t j, std::size_t k) {
            // Similar to the constant version, but this one returns a reference to allow modification
            // The formula calculates the index in the same way, but the return type is a reference (&),
            // so we can modify the element directly in the 'values' array.
            return values[height * width * k + width * i + j];
        };


        // Resize a tensor (3D) into a 1-dimensional vector
        std::vector<double> flatten() const { return values; };

        tensor_3d &operator*=(double x);

        tensor_3d &operator-=(const tensor_3d &other_tensor);

        tensor_3d &operator+=(const tensor_3d &other_tensor);

        tensor_3d operator*(const tensor_3d &other_tensor) const;

        void print() const;

        // GETTERS :
        size_t get_height() const;
        size_t get_width() const;
        size_t get_depth() const;

        const std::vector<double> &get_values() const;

        // SETTER :
        void set_values(const std::vector<double> &vs);

    }; // tensor_3d

} // namespace
#endif

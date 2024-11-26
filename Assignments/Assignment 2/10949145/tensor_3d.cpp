#include "tensor_3d.hpp"

namespace convnet {

    tensor_3d::tensor_3d(std::size_t h, std::size_t w, std::size_t d) : height(h), width(w), depth(d) {
    };

    tensor_3d::tensor_3d() : height(0), width(0), depth(0) {

    }

    tensor_3d::tensor_3d(const tensor_3d &T) : height(T.height), width(T.width), depth(T.depth), values(T.values) {
    };

    tensor_3d::tensor_3d(std::size_t h, std::size_t w, std::size_t d, std::vector<double> _values) : height(h),
                                                                                                     width(w), depth(d),
                                                                                                     values(_values) {
    };

    void tensor_3d::initialize_with_zeros() {
        std::size_t size = height * width * depth;
        values.reserve(size);
        for (std::size_t it = 0; it < size; it++) {
            values.push_back(0);
        };
    }

    void tensor_3d::initialize_with_random_normal(double mean, double variance) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::normal_distribution<double> distribution(mean, variance);
        values.clear();
        std::size_t size = height * width * depth;
        values.reserve(size);
        for (std::size_t i = 0; i < size; i++) {
            values.push_back(distribution(generator));
        }
    }

    tensor_3d &tensor_3d::operator*=(double d) {
        for (double& value : values) {
            value *= d;
        }
        return *this;
    };

    tensor_3d &tensor_3d::operator-=(const tensor_3d &T) {
        // Check if the dimensions (height, width, depth) of the current tensor
        // do not match the dimensions of the other tensor (T)
        if (T.height != height || T.width != width || T.depth != depth) {
            std::cerr <<"Dimensions (height, width, depth) of the two tensors must match."<<std::endl;
        }

        for (std::size_t i = 0; i < values.size(); ++i) {
            values[i] -= T.values[i];
        }

        return *this;
    };

    tensor_3d &tensor_3d::operator+=(const tensor_3d &T) {
        // Check if the dimensions (height, width, depth) of the current tensor
        // do not match the dimensions of the other tensor (T)
        if (T.height != height || T.width != width || T.depth != depth) {
            std::cerr << "Error: Dimensions (height, width, depth) of the two tensors must match." << std::endl;
        }

        for (std::size_t i = 0; i < values.size(); ++i) {
            values[i] += T.values[i];
        }

        return *this;
    };

    tensor_3d tensor_3d::operator*(const tensor_3d &T) const {
        // Check if the dimensions (height, width, depth) of the current tensor
        // do not match the dimensions of the other tensor (T)
        if (T.height != height || T.width != width || T.depth != depth) {
            std::cerr <<"Dimensions (height, width, depth) of the two tensors must match." <<std::endl;
        }

        tensor_3d out(*this);
        for (std::size_t i = 0; i < out.values.size(); ++i) {
            out.values[i] *= T.values[i];
        }
        return out;
    };

    void tensor_3d::print() const {
        for (std::size_t k = 0; k < depth; ++k) {
            for (std::size_t i = 0; i < height; i++) {
                for (std::size_t j = 0; j < width; j++) {
                    std::cout << values[k * width * height + i * width + j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "-----" << std::endl;
        }
    }

    std::size_t tensor_3d::get_height() const {
        return height;
    }

    std::size_t tensor_3d::get_width() const {
        return width;
    }

    std::size_t tensor_3d::get_depth() const {
        return depth;
    }

    const std::vector<double> &tensor_3d::get_values() const {
        return values;
    }

    void tensor_3d::set_values(const std::vector<double> &vs) {
        values = vs;
    };

} // namespace
#include "matrix.hpp"

namespace convnet {

    matrix::matrix(std::size_t nrs, std::size_t ncs) {
        n_rows = nrs;
        n_cols = ncs;
    }

    void matrix::initialize_with_random_normal(double mean, double variance) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::normal_distribution<double> distribution(mean, variance);
        values.clear();
        std::size_t size = n_rows * n_cols;
        values.reserve(size);
        for (std::size_t it = 0; it < size; it++) {
            values.push_back(distribution(generator));
        };
    }

    void matrix::initialize_with_zeros() {
        values.clear();
        std::size_t size = n_rows * n_cols;
        values.reserve(size);
        for (std::size_t it = 0; it < size; it++) {
            values.push_back(0.0);
        };
    }

    matrix &matrix::operator*=(double x) {
        for (double & value : values) {
            value *= x;
        }
        return *this;
    }

    matrix &matrix::operator-=(const matrix &other_matrix) {
        if (other_matrix.n_rows != n_rows || other_matrix.n_cols != n_cols) {
            std::cerr <<"Matrix dimensions must match for subtraction."<<std::endl;
            return *this;
        }

        for (std::size_t i = 0; i < values.size(); ++i) {
            values[i] -= other_matrix.values[i];
        }

        return *this;
    }

    std::vector<double> matrix::dot(const std::vector<double> &other_vector) const {
        if (other_vector.size() != n_cols) {
            std::cerr <<"Vector size must match the number of columns."<<std::endl;
            return {};
        }

        std::vector<double> out_vector;
        out_vector.reserve(other_vector.size());

        double tmp_value;
        std::size_t size = n_rows * n_cols;
        for (std::size_t it = 0; it < size;) {
            tmp_value = 0;
            for (double val: other_vector) {
                tmp_value += values[it] * val;
                ++it;
            }
            out_vector.push_back(tmp_value);
        };
        return out_vector;
    }

    std::vector<double> matrix::Tdot(const std::vector<double> &other_vector) const {
        if (other_vector.size() != n_rows) {
            std::cerr<<"Vector size must match the number of rows."<<std::endl;
            return {};
        }

        std::vector<double> out_vector;
        out_vector.reserve(other_vector.size());

        double tmp_value;
        for (std::size_t i = 0; i < n_cols; ++i) {
            tmp_value = 0;
            for (std::size_t j = 0; j < n_rows; ++j) {
                tmp_value += values[j * n_cols + i] * other_vector[j];
            }
            out_vector.push_back(tmp_value);
        };
        return out_vector;
    }


    void matrix::print() const {
        for (std::size_t i = 0; i < n_rows; i++) {
            for (std::size_t j = 0; j < n_cols; j++) {
                std::cout << values[i * n_cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    size_t matrix::get_n_rows() const {
        return n_rows;
    }


    size_t matrix::get_n_cols() const {
        return n_cols;
    }

    const std::vector<double> &matrix::get_values() const {
        return values;
    }

    void matrix::set_values(const std::vector<double> &vs) {
        values = vs;
    }

} // namespace
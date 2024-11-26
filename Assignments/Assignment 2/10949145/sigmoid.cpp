#include "sigmoid.hpp"

namespace convnet {

    std::vector<double> sigmoid::apply(const std::vector<double> &X) const {
        std::vector<double> out;
        for (double x: X) out.push_back(1.0 / (1.0 + std::exp(-x)));
        return out;
    }

    tensor_3d sigmoid::apply(const tensor_3d &X) const {
        std::vector<double> out_values;
        std::size_t out_size = X.get_values().size();
        out_values.reserve(out_size);

        for (std::size_t it = 0; it < out_size; ++it) {
            double val = X.get_values()[it];
            out_values.push_back(1.0 / (1.0 + std::exp(-val)));
        }

        return tensor_3d(X.get_height(), X.get_width(), X.get_depth(), out_values);
    }

} // namespace
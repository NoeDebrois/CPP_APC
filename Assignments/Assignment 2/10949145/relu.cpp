#include "relu.hpp"

namespace convnet {

    tensor_3d relu::apply(const tensor_3d &X) const {
        std::vector<double> out_values;
        std::size_t out_size = X.get_values().size();
        out_values.reserve(out_size);
        double val;
        for (std::size_t it = 0; it < out_size; ++it) {
            val = X.get_values()[it];
            out_values.push_back((val > 0.0) ? val : 0.0);
        }
        return tensor_3d(X.get_height(), X.get_width(), X.get_depth(), out_values);
    }

    std::vector<double> relu::apply(const std::vector<double> &X) const {
        std::vector<double> out;
        out.reserve(X.size());

        for (std::size_t it = 0; it < X.size(); ++it) {
            out.push_back(std::max(0.0, X[it]));
        }

        return out;
    }

} // namespace
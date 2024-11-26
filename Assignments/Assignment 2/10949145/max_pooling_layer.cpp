#include "max_pooling_layer.hpp"

namespace convnet {

    max_pooling_layer::max_pooling_layer(std::size_t s_filter, std::size_t strd) {
        size_filter = s_filter;
        stride = strd;
    };

    tensor_3d max_pooling_layer::evaluate(const tensor_3d &inputs) const {

        /* YOUR CODE SHOULD GO HERE */

    };


    tensor_3d max_pooling_layer::apply_activation(const tensor_3d &Z) const {
        return Z;
    };

    tensor_3d max_pooling_layer::forward_pass(const tensor_3d &inputs) const {

        /* YOUR CODE SHOULD GO HERE */

    };

    // Do nothing since max pooling has no learnable parameter
    void max_pooling_layer::set_parameters(const std::vector<std::vector<double>> parameters) {}

} // namespace
#ifndef CONVNET_ACTIVATION_FUNCTION_HPP
#define CONVNET_ACTIVATION_FUNCTION_HPP

#include <vector>
#include "tensor_3d.hpp"

namespace convnet {

// Abstract base class for activation functions
    class activation_function {
    public:
        virtual ~activation_function() = default;

        virtual tensor_3d apply(const tensor_3d &X) const = 0;

        virtual std::vector<double> apply(const std::vector<double> &X) const = 0;
    };

} // namespace convnet

#endif //CONVNET_ACTIVATION_FUNCTION_HPP

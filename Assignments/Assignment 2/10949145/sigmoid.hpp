#ifndef CONVNET_SIGMOID_HPP
#define CONVNET_SIGMOID_HPP

#include <vector>
#include "activation_function.hpp"
#include <cmath>

namespace convnet {

    class sigmoid : public activation_function {
    public:
        std::vector<double> apply(const std::vector<double> &X) const override;

        tensor_3d apply(const tensor_3d &X) const override;

    };

} // namespace convnet

#endif // CONVNET_SIGMOID_HPP

#ifndef CONVNET_RELU_HPP
#define CONVNET_RELU_HPP

#include <vector>
#include "activation_function.hpp"
#include "tensor_3d.hpp"

namespace convnet {

    class relu : public activation_function {
    public:
        tensor_3d apply(const tensor_3d &X) const override;

        std::vector<double> apply(const std::vector<double> &X) const override;
    };

} // namespace convnet

#endif // CONVNET_RELU_HPP

#ifndef CONVNET_FEATURE_LAYER_HPP
#define CONVNET_FEATURE_LAYER_HPP

#include <iostream>
#include <tensor_3d.hpp>
#include <vector>

namespace convnet {

    class feature_layer {
    public:
        virtual void initialize() = 0;

        virtual ~feature_layer() {};

        virtual tensor_3d evaluate(const tensor_3d &input) const = 0;

        virtual tensor_3d apply_activation(const tensor_3d &Z) const = 0;

        virtual tensor_3d forward_pass(const tensor_3d &inputs) const = 0;

        virtual std::vector<std::vector<double> > get_parameters() const = 0;

        virtual void set_parameters(const std::vector<std::vector<double>> parameters) = 0;

        virtual bool is_learnable() const = 0;
    };

} // namespace

#endif // CONVNET_LAYER3D_H_

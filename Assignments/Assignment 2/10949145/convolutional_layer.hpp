#ifndef CONVNET_CONVOLUTIONAL_LAYER_HPP
#define CONVNET_CONVOLUTIONAL_LAYER_HPP

#include <iostream>
#include <relu.hpp>
#include <feature_layer.hpp>
#include <list>

namespace convnet {

    class convolutional_layer : public feature_layer {
    private:
        relu act_function;
        std::size_t s_filter, n_filters, s_stride, s_padding;
        std::size_t prev_depth;

    public:
        std::vector<tensor_3d> filters;

        convolutional_layer(std::size_t _s_filter, std::size_t _prev_depth, std::size_t _n_filters,
                            std::size_t _s_stride, std::size_t _s_padding);

        virtual ~convolutional_layer() {};

        void initialize() override;

        tensor_3d evaluate(const tensor_3d &inputs) const override;

        tensor_3d apply_activation(const tensor_3d &Z) const override;

        tensor_3d forward_pass(const tensor_3d &inputs) const override;

        std::vector<std::vector<double>> get_parameters() const override;

        void set_parameters(const std::vector<std::vector<double>> parameters) override;

        bool is_learnable() const override { return true; }
    };

} // namespace convnet

#endif // CONVNET_CONVOLUTIONAL_LAYER_HPP

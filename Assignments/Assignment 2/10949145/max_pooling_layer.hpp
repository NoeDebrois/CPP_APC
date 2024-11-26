#ifndef CONVNET_MAX_POOLING_LAYER_HPP
#define CONVNET_MAX_POOLING_LAYER_HPP

#include <iostream>
#include <feature_layer.hpp>

namespace convnet {

    class max_pooling_layer : public feature_layer {
    private:
        std::size_t size_filter, stride;

    public:
        max_pooling_layer(std::size_t s_filter, std::size_t strd);

        virtual ~max_pooling_layer() {};

        void initialize() override {};

        tensor_3d evaluate(const tensor_3d &inputs) const override;

        tensor_3d apply_activation(const tensor_3d &Z) const override;

        tensor_3d forward_pass(const tensor_3d &inputs) const override;

        // return an empty vector since a max pooling filter does not have learnable parameters
        std::vector<std::vector<double>> get_parameters() const override {
            std::vector<std::vector<double>> v;
            return v;
        }

        void set_parameters(const std::vector<std::vector<double>> parameters) override;

        bool is_learnable() const override { return false; };
    };

} // namespace convnet

#endif // CONVNET_MAX_POOLING_LAYER_HPP

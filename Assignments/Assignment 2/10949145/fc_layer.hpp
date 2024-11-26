#ifndef CONVNET_FC_LAYER_HPP
#define CONVNET_FC_LAYER_HPP

#include <matrix.hpp>
#include <sigmoid.hpp>

namespace convnet {
    // Implementation of the fully-connected layer
    class fc_layer {
    private:
        sigmoid act_function;
        matrix weights;
        std::size_t size_in, size_out;

    public:

        fc_layer(std::size_t s_in, std::size_t s_out);

        void initialize();

        std::vector<double> forward_pass(const std::vector<double> &inputs) const;

        std::vector<double> compute(const std::vector<double> &inputs) const;

        std::vector<double> apply_activation(const std::vector<double> &z) const;

        std::vector<double> get_parameters() const;

        void set_parameters(const std::vector<double> parameters);

        const matrix &get_weights() const;

        void set_weights(const matrix & ws);

        std::size_t get_size_in() const;

        std::size_t get_size_out() const;

    }; //fc_layer

} // namespace
#endif // CONVNET_FC_LAYER_HPP


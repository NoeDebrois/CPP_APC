#include "fc_layer.hpp"

namespace convnet {

    fc_layer::fc_layer(std::size_t s_in, std::size_t s_out) : size_in(s_in), size_out(s_out) {
        initialize();
    };

    void fc_layer::initialize() {
        weights = matrix(size_out, size_in);
        weights.initialize_with_random_normal(0.0, 2.0 / (size_in + size_out));
    };

    std::vector<double> fc_layer::apply_activation(const std::vector<double> &z) const {
        return act_function.apply(z);
    };

    std::vector<double> fc_layer::compute(const std::vector<double> &inputs) const {
        // Computes the weighted sum of the inputs with the layer weights, returning
        // the raw output (without activation). This implements the equation 1. For
        // simplicity, we consider the bias b as 0. Here is equation 1 :
        // y(x) = f(Sum_{i=1}^{n} w_i * x_i + b), where x \in R^n is the INPUT vector,
        // w \in R^n is the weight vector, b \in R is the bias (= 0 here) and f(.) the
        // activation function (here : sigmoid, cf .hpp).

        /* MY CODE */
        // 1 Get the weights w :
        const matrix w = weights;

        // 2 Perform the dot product between weights and inputs :
        std::vector<double> raw_output = w.dot(inputs);

        // 3 Return the raw output (without activation) :
        return raw_output;
    };

    std::vector<double> fc_layer::forward_pass(const std::vector<double> &inputs) const {
        // Executes a forward pass through the layer, applying the weights and
        // activation function to the input vector and returning the output vector.
        // Here the activation function is a sigmoid.

        /* MY CODE */
        // 0 Debugging :
        // std::cout << "Expected input size: " << size_in << ", provided: " << inputs.size() << std::endl;

        // 1 Compute the raw output :
        std::vector<double> raw_output = compute(inputs);

        // 2 Apply the activation :
        std::vector<double> activated_output = apply_activation(raw_output);

        // 3 Return the activated output :
        return activated_output;
    };

    std::vector<double> fc_layer::get_parameters() const {
        return weights.get_values();
    }

    void fc_layer::set_parameters(const std::vector<double> parameters) {
        weights.set_values(parameters);
    }

    const matrix &fc_layer::get_weights() const {
        return weights;
    }

    void fc_layer::set_weights(const matrix &ws) {
        weights = ws;
    }

    std::size_t fc_layer::get_size_in() const {
        return size_in;
    }

    std::size_t fc_layer::get_size_out() const {
        return size_out;
    }


} // namespace
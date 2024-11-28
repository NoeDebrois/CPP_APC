#include "max_pooling_layer.hpp"

namespace convnet {

    max_pooling_layer::max_pooling_layer(std::size_t s_filter, std::size_t strd) {
        size_filter = s_filter;
        stride = strd;
    };

    tensor_3d max_pooling_layer::evaluate(const tensor_3d &inputs) const {
        // 1 Extract input dimensions:
        const std::size_t H = inputs.get_height();
        const std::size_t W = inputs.get_width();
        const std::size_t D = inputs.get_depth();

        // 2 Get filter's dimensions (only 1 "filter" here, i.e the sliding window):
        const std::size_t FH = size_filter;
        const std::size_t FW = size_filter;

        // 3 Compute the output's dimensions:
        const std::size_t Hout = (H - FH) / stride + 1;
        const std::size_t Wout = (W - FW) / stride + 1;

        // 4 Initialize output tensor with zeros:
        tensor_3d output(Hout, Wout, D); // Depth D preserved !
        output.initialize_with_zeros();

        // 5 Perform Max Pooling depth by depth:
        for (std::size_t d = 0; d < D; ++d) { // For each depth slice..
            for (std::size_t i = 0; i < Hout; ++i) { // For each output row...
                for (std::size_t j = 0; j < Wout; ++j) { // For each output column...
                    // Initialize the maximum value for this window and depth slice
                    double max_value = std::numeric_limits<double>::lowest();
                    // Iterate over the sliding window
                    for (std::size_t h = 0; h < FH; ++h) { // Sliding window height
                        for (std::size_t w = 0; w < FW; ++w) { // Sliding window width
                            // Get the current input value for depth `d`
                            double current_value = inputs(i * stride + h, j * stride + w, d);
                            // Update max_value if the current value is larger
                            max_value = std::max(max_value, current_value);
                        }
                    }
                    // Assign the maximum value to the output tensor for depth `d`
                    output(i, j, d) = max_value;
                }
            }
        }
        // 6 Return the output tensor:
        return output;
    };


    tensor_3d max_pooling_layer::apply_activation(const tensor_3d &Z) const {
        return Z;
    };

    tensor_3d max_pooling_layer::forward_pass(const tensor_3d &inputs) const {
        // Method that performs a forward pass of the layer to the input. The
        // output is obtained after applying the activation to the result of the
        // evaluate function. For a Max pooling layer, a forward pass means
        // performing only the max pooling operation since no activation function
        // is required.

        /* MY CODE */
        // 1 Perform the convolution operation using "evaluate" :
        tensor_3d After_Max_Pooling = evaluate(inputs);

        // 2 Apply the activation function to the maxpooling result. Here, it will
        // do nothing since no activation is required (cf the above function) :
        tensor_3d Fwd_Passed_Output = apply_activation(After_Max_Pooling);

        // 3 Return the activated output :
        return Fwd_Passed_Output;
    };

    // Do nothing since max pooling has no learnable parameter
    void max_pooling_layer::set_parameters(const std::vector<std::vector<double>> parameters) {}

} // namespace
#include "max_pooling_layer.hpp"

namespace convnet {

    max_pooling_layer::max_pooling_layer(std::size_t s_filter, std::size_t strd) {
        size_filter = s_filter;
        stride = strd;
    };

    tensor_3d max_pooling_layer::evaluate(const tensor_3d &inputs) const {
        // METHOD :
        // Performs the max pooling on the input with the pooling filter as described
        // in Equation (7) (cf below).
        // It selects the maximum value within a sliding window. For an input tensor
        // IM with dimensions(H, W, D), a window(filter) of size (FH, FW) and a stride,
        // the output dimensions are : Hout = (H - FH) / stride + 1, Wout = (W - FW) / stride + 1.
        // For each position (i, j, d) in the output tensor, the max pooling operation is defined as :
        // Output[i, j, d] = max_{0<=h<FH ; 0<=w<FW} IM[i * stride + h, j * stride + w, d] (7).
        // In other words, the max operation takes the maximum value within each (FH x FW) window
        // along the depth dimension d.

        /* MY CODE */
        // 1 Extract input dimensions :
        const std::size_t H = inputs.get_height();
        const std::size_t W = inputs.get_width();
        const std::size_t D = inputs.get_depth();

        // 2 We already have stride in the name of 'stride'.

        // 3 Get filter's dimensions (only 1 "filter" here, i.e the sliding window) :
        const std::size_t FH = size_filter;
        const std::size_t FW = size_filter;

        // 4 Compute the output's dimensions :
        const std::size_t Hout = (H - FH) / stride + 1;
        const std::size_t Wout = (W - FW) / stride + 1;

        // 5 Initialize output tensor with zeros :
        tensor_3d output(Hout, Wout, 1);
        output.initialize_with_zeros();

        // 6 Perform Max Pooling :
        for (std::size_t i = 0; i < Hout; ++i) {
            // For each output row...
            for (std::size_t j = 0; j < Wout; ++j) {
                // For each output column...
                // Initialize the maximum value for this window
                double max_value = std::numeric_limits<double>::lowest();
                // Iterate over the sliding window
                for (std::size_t h = 0; h < FH; ++h) { // Sliding window height
                    for (std::size_t w = 0; w < FW; ++w) { // Sliding window width
                        for (std::size_t d = 0; d < D; ++d) {
                            // Iterate over depth
                            // Get the current input value
                            double current_value = inputs(i * stride + h, j * stride + w, d);
                            // Update max_value if the current value is larger
                            max_value = std::max(max_value, current_value);
                        }
                    }
                }
                // Assign the maximum value to the output tensor
                output(i, j, 0) = max_value;
            }
        }
        // 7 Return the output tensor, i.e the result of the input max-pooling with sliding-window :
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
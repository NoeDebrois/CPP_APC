#include "convolutional_layer.hpp"

namespace convnet {

    convolutional_layer::convolutional_layer(std::size_t _s_filter, std::size_t _prev_depth, std::size_t _n_filters,
                                             std::size_t _s_stride, std::size_t _s_padding)
            : s_filter(_s_filter), prev_depth(_prev_depth), n_filters(_n_filters), s_stride(_s_stride),
              s_padding(_s_padding) {
        initialize();
    }

    void convolutional_layer::initialize() {
        for (std::size_t it = 0; it < n_filters; ++it) {
            tensor_3d filter(s_filter, s_filter, prev_depth);
            filter.initialize_with_random_normal(0.0, 3.0 / (2 * s_filter + prev_depth));
            filters.push_back(filter);
        }
    }

    tensor_3d convolutional_layer::evaluate(const tensor_3d &inputs) const {
        // METHOD :
        // Performs the convolution of input with convolutional filter as in Equation (4) [pages 2-3] :
        // Output[i, j, k] = Sum_h(Sum_w(Sum_d(IM_padded[i * stride + h,
        //                                               j * stride + w, d] * Fk[h, w, d])))
        // with IM_padded = IM since in the assignment we consider a padding of zero ;
        // & with h \in {0, 1, ..., F_H - 1}, w \in {0, 1, ..., F_W - 1}, d \in {0, 1, ..., D - 1}.
        // RECALL :
        // - Stride: The stride controls the step size of the filter as it moves across the input.
        // A larger stride reduces the spatial dimensions of the output, as fewer regions are covered.
        // - Padding: Padding adds extra borders to the input tensor, allowing filters to overlap edge
        // regions fully. This prevents a reduction in output size and helps retain spatial information
        // at the edges.

        /* MY CODE */
        // 1 Extract input dimensions :
        const std::size_t H = inputs.get_height();
        const std::size_t W = inputs.get_width();
        const std::size_t D = inputs.get_depth(); // It is also the filters' depth.

        // 2 Extract padding / stride parameters :
        const std::size_t padding = s_padding;
        const std::size_t stride = s_stride;

        // 3 Get filters' dimensions :
        const std::size_t nfilters = n_filters;
        const std::size_t FH = s_filter;  // CHECK THAT !
        const std::size_t FW = s_filter;  // CHECK THAT !

        // 4 Compute the output's dimensions :
        const std::size_t Hout = (H - FH + 2 * padding) / stride + 1;
        const std::size_t Wout = (W - FW + 2 * padding) / stride + 1;
        // And Dout is equal to the number of filters.

        // 5 Initialize output tensor with zeros :
        tensor_3d output(Hout, Wout, nfilters);
        output.initialize_with_zeros();

        // 6 Convolution formula :
        for (std::size_t k = 0; k < nfilters; ++k) {
            // For each filter...
            const tensor_3d &filter = filters[k]; // Get the k-th filter.
            for (std::size_t i = 0; i < Hout; ++i) {
                // For each output row...
                for (std::size_t j = 0; j < Wout; ++j) {
                    // For each output column...
                    // Implement the formula, Output[i, j, k] = ...
                    double Output_i_j_k = 0.0; // Initialize the value of Output[i, j, k] to 0.
                    for (std::size_t h = 0; h < FH; ++h) {
                        // Filter height
                        for (std::size_t w = 0; w < FW; ++w) {
                            // Filter width
                            for (std::size_t d = 0; d < D; ++d) {
                                // Filter depth
                                Output_i_j_k += inputs(i * stride + h, j * stride + w, d) *
                                    filter(h, w, d);
                            }
                        }
                    }
                    output(i, j, k) = Output_i_j_k; // Assign the value of the output @ coord (i, j, k).
                }
            }
        }
        // 7 Return the output, i.e the result of the convolution of the input with the filter :
        return output;
    }

    tensor_3d convolutional_layer::apply_activation(const tensor_3d &Z) const {
        return act_function.apply(Z);
    }

    tensor_3d convolutional_layer::forward_pass(const tensor_3d &inputs) const {
        // METHOD :
        // Performs a forward pass of the layer to the input. The output is obtained after applying
        // the activation to the result of the evaluate function.
        //
        /* MY CODE */
        // 1 Perform the convolution operation using "evaluate" :
        tensor_3d After_Conv = evaluate(inputs);

        // 2 Apply the activation function (ReLu) to the convolution result :
        tensor_3d Fwd_Passed_Output = apply_activation(After_Conv);

        // 3 Return the activated output :
        return Fwd_Passed_Output;
    }


    std::vector<std::vector<double>> convolutional_layer::get_parameters() const {
        std::vector<std::vector<double> > parameters;
        for (tensor_3d filter: filters) {
            parameters.push_back(filter.get_values());
        }
        return parameters;
    }

    void convolutional_layer::set_parameters(const std::vector<std::vector<double>> parameters) {
        for (std::size_t i = 0; i < n_filters; ++i) {
            filters[i].set_values(parameters[i]);
        }
    }

} // namespace
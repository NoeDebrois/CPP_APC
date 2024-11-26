#include "cnn.hpp"

namespace convnet {

// Constructor for the cnn class, which initializes the feature extractor layers and classifier layers (fully connected layers)
    cnn::cnn(std::vector<std::shared_ptr<feature_layer>> feature_ext, std::vector<fc_layer> classif) :
            feature_extractor(std::move(feature_ext)), classifier(std::move(classif)) {
        initialize();  // Initialize all layers after constructing the CNN
    }

// Initialize all layers in the feature extractor and classifier
    void cnn::initialize() {
        // Initialize each feature extraction layer
        for (std::shared_ptr<feature_layer> l: feature_extractor) l->initialize();

        // Initialize each classifier layer
        for (fc_layer l: classifier) l.initialize();
    }

// Set the test dataset consisting of images and their corresponding labels
    void
    cnn::set_test_dataset(std::shared_ptr<std::vector<tensor_3d>> images, std::shared_ptr<std::vector<int>> labels) {
        test_images = images;
        test_labels = labels;
    }

// Calculate the logits (raw predictions) for a given set of input images
    std::vector<std::vector<double>> cnn::get_logits(const std::vector<tensor_3d> inputs) const {
        std::vector<std::vector<double>> outputs;
        outputs.reserve(inputs.size());  // Reserve space for outputs

        tensor_3d feature_out;  // Holds the 3D output of feature extraction
        std::vector<double> output;  // Holds the flattened output after the classifier layers

        // Process each input image
        for (const tensor_3d &image: inputs) {

            // Forward pass through all layers in the feature extractor
            feature_out = image;
            for (std::shared_ptr<feature_layer> l: feature_extractor) feature_out = l->forward_pass(feature_out);

            // Flatten the output and forward pass through the classifier layers
            output = feature_out.flatten();
            for (fc_layer l: classifier) output = l.forward_pass(output);

            // Store the final output for the image
            outputs.push_back(output);
        }
        return outputs;  // Return the collection of logits
    }

// Predict the labels for a set of input images based on the logits
    std::vector<int> cnn::predict(const std::vector<tensor_3d> inputs) const {
        std::vector<int> predictions;
        predictions.reserve(inputs.size());  // Reserve space for predictions

        std::vector<std::vector<double>> logits;
        logits.reserve(inputs.size());  // Reserve space for logits

        logits = cnn::get_logits(inputs);  // Get logits for the inputs

        // Find the label with the highest logit for each image
        for (const std::vector<double>& logit_vector : logits) {
            // std::max_element returns an iterator to the element with the highest value
            // std::distance calculates the index (distance) between the beginning of the vector
            // and the iterator returned by std::max_element
            int output = std::distance(logit_vector.begin(),
                                       std::max_element(logit_vector.begin(), logit_vector.end()));

            // Store the index of the maximum element as the predicted label (class)
            predictions.push_back(output);  // Add the predicted label to the predictions vector
        }
        return predictions;  // Return the predicted labels
    }

// Compute the probabilities (after applying softmax) for each image's logits
    std::vector<std::vector<double>> cnn::get_probabilities(const std::vector<tensor_3d> inputs) const {
        std::vector<std::vector<double>> outputs;
        outputs.reserve(inputs.size());  // Reserve space for outputs

        std::vector<std::vector<double>> logits;
        logits.reserve(inputs.size());  // Reserve space for logits

        logits = cnn::get_logits(inputs);  // Get logits for the inputs

        // Apply softmax to convert logits into probabilities
        for (const std::vector<double> &logit_vector: logits) {
            double max_logit = *std::max_element(logit_vector.begin(),
                                            logit_vector.end());  // Max logit for numerical stability
            double sum_exp = 0.0;

            // Compute the sum of the exponentials of the logits, adjusted for numerical stability
            for (double logit: logit_vector) {
                sum_exp += std::exp(logit - max_logit);  // Subtract max_logit to prevent overflow
            }

            std::vector<double> probabilities;
            for (double logit: logit_vector) {
                probabilities.push_back(std::exp(logit - max_logit) / sum_exp);  // Convert logit to probability
            }

            outputs.push_back(probabilities);  // Store the computed probabilities
        }

        return outputs;  // Return the probabilities for all inputs
    }

// Print the output vectors (logits or probabilities) in a formatted manner
    void cnn::print_outputs(const std::vector<std::vector<double>> outputs) const {
        for (const std::vector<double> &output: outputs) {
            std::cout << "[";
            for (std::size_t i = 0; i < output.size(); ++i) {
                std::cout << output[i];
                if (i < output.size() - 1) {
                    std::cout << " ";  // Space between elements
                }
            }
            std::cout << "]" << std::endl;  // Close the output vector
        }
    }

// Print the predicted labels in a formatted manner
    void cnn::print_predictions(const std::vector<int> outputs) const {
        if (outputs.empty()) {
            std::cout << "No predictions to print." << std::endl;
            return;
        }

        std::cout << "[";
        for (std::size_t i = 0; i < outputs.size(); ++i) {
            std::cout << static_cast<int>(outputs[i]);  // Print each predicted label as an integer
            if (i < outputs.size() - 1) {
                std::cout << " ";  // Space between elements
            }
        }
        std::cout << "]" << std::endl;  // Close the prediction vector
    }

// Serialize and save the learnable parameters of the network to a file
    std::ostream &operator<<(std::ostream &os, const cnn &network) {
        // Save parameters of the feature extractor layers (if they are learnable)
        for (std::shared_ptr<feature_layer> l: network.feature_extractor) {
            if (l->is_learnable()) {
                for (std::vector<double> vec: l->get_parameters()) {
                    for (double param: vec) {
                        os << param << '\n';  // Save each parameter
                    }
                }
            }
        }

        // Save parameters of the classifier layers
        for (fc_layer l: network.classifier) {
            for (double parameter: l.get_parameters()) {
                os << parameter << '\n';  // Save each parameter
            }
        }

        return os;  // Return the stream
    }

// Save the parameters of the network to a file
    void cnn::save(const std::string &name) const {
        std::ofstream ofs(name + ".txt");
        ofs << (*this);  // Write the network parameters to the file
        ofs.close();
    }

// Deserialize and load the learnable parameters of the network from a file
    std::istream &operator>>(std::istream &is, cnn &network) {
        double p;
        std::vector<std::vector<double>> parameters3d;
        std::vector<double> tmp;
        std::vector<double> parameters2d;

        std::size_t n_vec, length3d;

        // Load parameters for the feature extractor layers
        for (std::shared_ptr<feature_layer> l: network.feature_extractor) {
            if (l->is_learnable()) {
                parameters3d.clear();
                n_vec = l->get_parameters().size();
                length3d = l->get_parameters()[0].size();
                for (std::size_t n = 0; n < n_vec; ++n) {
                    tmp.clear();
                    for (std::size_t s = 0; s < length3d; ++s) {
                        is >> p;
                        tmp.push_back(p);  // Load the parameter
                    }
                    parameters3d.push_back(tmp);  // Add the loaded parameters for this layer
                }
                l->set_parameters(parameters3d);  // Set the parameters for this layer
            }
        }

        // Load parameters for the classifier layers
        for (fc_layer &l: network.classifier) {
            parameters2d.clear();
            for (std::size_t s = 0; s < l.get_parameters().size(); ++s) {
                is >> p;
                parameters2d.push_back(p);  // Load the parameter
            }
            l.set_parameters(parameters2d);  // Set the parameters for this layer
        }

        return is;  // Return the stream
    }

// Load the parameters of the network from a file
    void cnn::load(const std::string &name) {
        std::ifstream ifs(name + ".txt");
        ifs >> *this;  // Read the network parameters from the file
        ifs.close();
    }

// Return a shared pointer to the test images
    std::shared_ptr<std::vector<tensor_3d>> cnn::get_test_images() const {
        return test_images;
    }

} // namespace

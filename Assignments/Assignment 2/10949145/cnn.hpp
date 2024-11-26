#ifndef CONVNET_CNN_HPP
#define CONVNET_CNN_HPP

#include <iostream>
#include <iterator>
#include <ctime>
#include <fstream>
#include <memory>

#include "tensor_3d.hpp"
#include "dataset.hpp"
#include "fc_layer.hpp"
#include "convolutional_layer.hpp"
#include "max_pooling_layer.hpp"

namespace convnet {

// The cnn class represents a Convolutional Neural Network (CNN).
// It includes a feature extractor (a sequence of convolutional and max pooling layers)
// and a classifier (a sequence of fully connected layers).
// This class provides methods for interacting with the network, such as setting datasets,
// and making predictions.
    class cnn {

    private:
        std::shared_ptr<std::vector<tensor_3d>> test_images;   // Shared pointer to test images for evaluation
        std::shared_ptr<std::vector<int>> test_labels;      // Shared pointer to test labels for evaluation
        std::vector<std::shared_ptr<feature_layer>> feature_extractor;  // List of feature extraction layers (e.g., convolution and pooling layers)
        std::vector<fc_layer> classifier;        // List of fully connected layers for classification

    public:
        // Constructor: Initializes the CNN with the given feature extraction layers and classifier layers
        cnn(std::vector<std::shared_ptr<feature_layer>> feature_ext, std::vector<fc_layer> classif);

        // Returns a shared pointer to the test images
        std::shared_ptr<std::vector<tensor_3d>> get_test_images() const;

        // Initializes all layers in the network
        void initialize();

        // Sets the test dataset (images and labels) for evaluation
        void
        set_test_dataset(std::shared_ptr<std::vector<tensor_3d>> images, std::shared_ptr<std::vector<int>> labels);

        // Takes a vector of input images and returns a vector of predicted labels
        std::vector<int> predict(const std::vector<tensor_3d> inputs) const;

        // Computes and returns the logits (raw outputs) for a given set of input images
        std::vector<std::vector<double>> get_logits(const std::vector<tensor_3d> inputs) const;

        // Computes and returns the probabilities (after softmax) for a given set of input images
        std::vector<std::vector<double>> get_probabilities(const std::vector<tensor_3d> inputs) const;

        // Prints the outputs (logits or probabilities) to the console
        void print_outputs(const std::vector<std::vector<double>> outputs) const;

        // Prints the predicted labels to the console
        void print_predictions(const std::vector<int> outputs) const;

        // Overloaded output stream operator to save the learnable parameters of the network to a file
        friend std::ostream &operator<<(std::ostream &os, const cnn &network);

        void save(const std::string &name) const;

        // Overloaded input stream operator to load the learnable parameters from a file
        friend std::istream &operator>>(std::istream &is, cnn &network);

        void load(const std::string &name);

    }; // cnn

} // namespace

#endif // CONVNET_CNN_HPP

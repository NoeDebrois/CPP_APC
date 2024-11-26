
#ifndef CONVNET_TEST_HPP
#define CONVNET_TEST_HPP

#include <iostream>
#include "tensor_3d.hpp"
#include "convolutional_layer.hpp"
#include "max_pooling_layer.hpp"
#include "matrix.hpp"
#include "fc_layer.hpp"
#include "cnn.hpp"
#include "dataset.hpp"

using namespace convnet;

void test1() {
    std::vector<double> values = {-1, 3, 2, 0,
                                  1, -2, 1, 0,
                                  2, 0, -3, 2,
                                  1, 1, 0, 2};
    tensor_3d t1(4, 4, 1, values);

    convolutional_layer c1(2, 1, 1, 1, 0);
    std::vector<double> values_filter = {1, 2, 1, 0};
    c1.filters.at(0).set_values(values_filter);

    auto res_1 = c1.evaluate(t1);

    std::cout << "t1" << std::endl;
    t1.print();
    std::cout << "filter" << std::endl;
    c1.filters.at(0).print();
    std::cout << "convolution t1 * filter = " << std::endl;
    res_1.print();
}

void test2() {
    std::vector<double> values = {-1, 3, 2, 0,
                                  1, -2, 1, 0,
                                  2, 0, -3, 2,
                                  1, 1, 0, 2};
    tensor_3d t1(4, 4, 1, values);

    convolutional_layer c1(2, 1, 1, 1, 0);
    std::vector<double> values_filter = {1, 2, 1, 0};
    c1.filters.at(0).set_values(values_filter);

    auto res_1 = c1.evaluate(t1);

    auto res_2 = c1.forward_pass(t1);

    std::cout << "t1" << std::endl;
    t1.print();
    std::cout << "filter" << std::endl;
    c1.filters.at(0).print();
    std::cout << "convolution t1 * filter = " << std::endl;
    res_1.print();
    std::cout << "forward_pass(t1) [applying relu to output of evaluate] = " << std::endl;
    res_2.print();
}

void test3() {
    std::vector<double> values = {1, 3, 2, -1,
                                  1, 2, 1, 0,
                                  -2, 0, 4, 2,
                                  1, 1, 0, 2};
    tensor_3d t1(4, 4, 1, values);

    max_pooling_layer mp1(2, 2);

    auto res_1 = mp1.evaluate(t1);

    std::cout << "t1" << std::endl;
    t1.print();
    std::cout << "max pooling t1 with window (2x2) and stride 2 = " << std::endl;
    res_1.print();
}

void test4() {
    std::vector<double> values = {1, 3, 2, -1,
                                  1, 2, 1, 0,
                                  -2, 0, 4, 2,
                                  1, 1, 0, 2};
    tensor_3d t1(4, 4, 1, values);

    max_pooling_layer mp1(2, 2);

    auto res_1 = mp1.evaluate(t1);

    auto res_2 = mp1.forward_pass(t1);

    std::cout << "t1" << std::endl;
    t1.print();
    std::cout << "max pooling t1 with window (2x2) and stride 2 = " << std::endl;
    res_1.print();
    std::cout << "max pooling forward_pass(t1) = " << std::endl;
    res_2.print();
}

void test5() {
    std::vector<double> values = {1, 3, 2};
    matrix input(3, 1);
    input.set_values(values);
    fc_layer fc(3, 2);

    matrix fc_weights(2, 3);
    std::vector<double> fc_weights_values = {0.2, 0.3,
                                             0.1, 0.5,
                                             0.1, 0.2};

    fc_weights.set_values(fc_weights_values);
    fc.set_weights(fc_weights);

    auto res_1 = fc.compute(input.get_values());

    std::cout << "input : " << std::endl;
    input.print();

    std::cout << std::endl;
    std::cout << "fc weights" << std::endl;
    fc.get_weights().print();

    std::cout << std::endl;
    std::cout << "result = " << std::endl;

    for (std::size_t j = 0; j < res_1.size(); j++) {
        std::cout << res_1[j] << " ";
    }
    std::cout << std::endl;
}

void test6() {
    std::vector<double> values = {1, 3, 2};
    matrix input(3, 1);
    input.set_values(values);
    fc_layer fc(3, 2);

    matrix fc_weights(2, 3);
    std::vector<double> fc_weights_values = {0.2, 0.3,
                                             0.1, 0.5,
                                             0.1, 0.2};

    fc_weights.set_values(fc_weights_values);
    fc.set_weights(fc_weights);

    auto res_1 = fc.compute(input.get_values());
    auto res_2 = fc.forward_pass(input.get_values());

    std::cout << "input : " << std::endl;
    input.print();
    std::cout << std::endl;
    std::cout << "fc weights" << std::endl;
    fc.get_weights().print();
    std::cout << std::endl;
    std::cout << "result compute = " << std::endl;

    for (std::size_t j = 0; j < res_1.size(); j++) {
        std::cout << res_1[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "result forward_pass(applying sigmoid) = " << std::endl;

    for (std::size_t j = 0; j < res_2.size(); j++) {
        std::cout << res_2[j] << " ";
    }
    std::cout << std::endl;
}

void test7() {
// Paths to the database
    std::string filename_test_images = "../dataset/t10k-images-idx3-ubyte";
    std::string filename_test_labels = "../dataset/t10k-labels-idx1-ubyte";
    std::string weights = "../weights/trained_weights";

// Feature detector architecture using shared pointers
    std::shared_ptr<feature_layer> conv1 = std::make_shared<convolutional_layer>(5, 1, 6, 1, 0);
    std::shared_ptr<feature_layer> pool1 = std::make_shared<max_pooling_layer>(2, 2);
    std::shared_ptr<feature_layer> conv2 = std::make_shared<convolutional_layer>(5, 6, 16, 1, 0);
    std::shared_ptr<feature_layer> pool2 = std::make_shared<max_pooling_layer>(2, 2);

    std::vector<std::shared_ptr<feature_layer>> feature_detector{conv1, pool1, conv2, pool2};

// Classifier architecture (no need for shared pointers here if not required by cnn class)
    fc_layer fc1(4 * 4 * 16, 84);
    fc_layer fc2(84, 10);
    std::vector<fc_layer> classifier{fc1, fc2};

// Building the network with shared pointers in feature_detector
    convnet::cnn network(feature_detector, classifier);

// Read and set the test dataset
    dataset dataset_handler;
    std::vector<tensor_3d> test_images = dataset_handler.load_images_mnist_dataset(filename_test_images);
    std::vector<int> test_labels = dataset_handler.load_labels_mnist_dataset(filename_test_labels);

// Create shared_ptr for the test images and labels
    std::shared_ptr<std::vector<tensor_3d>> test_images_ptr = std::make_shared<std::vector<tensor_3d>>(test_images);
    std::shared_ptr<std::vector<int>> test_labels_ptr = std::make_shared<std::vector<int>>(test_labels);

// Set the test dataset using shared_ptr
    network.set_test_dataset(test_images_ptr, test_labels_ptr);

// Sample test inputs
    std::vector<tensor_3d> tests = {network.get_test_images()->at(12), network.get_test_images()->at(912),
                                    network.get_test_images()->at(9014)};

// Load weights, make predictions, and display results
    network.load(weights);

    std::cout << "class predictions: " << std::endl;
    network.print_predictions(network.predict(tests));

    dataset_handler.show_image(tests.at(0));
    dataset_handler.show_image(tests.at(1));
    dataset_handler.show_image(tests.at(2));
}

#endif

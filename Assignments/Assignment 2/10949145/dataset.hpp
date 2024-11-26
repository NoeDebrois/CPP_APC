#ifndef CONVNET_DATASET_HPP
#define CONVNET_DATASET_HPP

#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <iostream>
#include <tensor_3d.hpp>

namespace convnet {

// This class is mainly for handling the MNIST datatset for digit recognition
// the dataset and explanation of file formats are located on
// http://yann.lecun.com/exdb/mnist/
    class dataset {

    public:
        std::vector<tensor_3d> load_images_mnist_dataset(std::string &filename) const;

        std::vector<int> load_labels_mnist_dataset(std::string &filename) const;

        void show_image(tensor_3d &image) const;
    };

} // namespace
#endif // CONVNET_DATASET_HPP

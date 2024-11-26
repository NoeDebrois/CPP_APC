#include "dataset.hpp"

namespace convnet {

    // Convert a 4-length char into the corresponding int
    int char4_to_int(char *p) {
        return (int8_t) p[0] * std::pow(2, 24)
               + (int8_t) p[1] * std::pow(2, 16)
               + (int8_t) p[2] * std::pow(2, 8)
               + (int8_t) p[3];
    }

    // This method helps in loading images to a std::vector<tensor_3d>.
    // It is a helper method which follows the description of the dataset by the authors.
    std::vector<tensor_3d> dataset::load_images_mnist_dataset(std::string &filename) const {
        std::ifstream dataset_file(filename, std::ios::binary);

        // Check if the dataset file could not be opened
        if (!dataset_file.is_open()) {
            std::cerr<<"Failed to open the dataset file."<<std::endl;
            return {};
        }

        std::vector<tensor_3d> images;

        int8_t size_of_int32 = sizeof(int32_t);
        char tmp[size_of_int32];

        // assert if dataset_file format is appropriate
        dataset_file.read(tmp, size_of_int32);
        int32_t magic_number = char4_to_int(tmp);

        if (magic_number != 0x803) {
            std::cerr<<"Magic number does not match the expected value."<<std::endl;
            return {};
        }

        (void) magic_number;

        // getting the number of images
        dataset_file.read(tmp, size_of_int32);
        int32_t number_of_images = char4_to_int(tmp);

        // getting the number of rows per image
        dataset_file.read(tmp, size_of_int32);
        int32_t nrows = char4_to_int(tmp);

        // getting the number of columns per image
        dataset_file.read(tmp, size_of_int32);
        int32_t ncols = char4_to_int(tmp);


        // Get images
        int size = nrows * ncols;
        char *buffer = new char[size];

        // We loop through all images
        for (int n = 0; n < number_of_images; ++n) {
            // Read a single image and buffer it as a vector of double
            dataset_file.read(buffer, size);
            std::vector<double> image;
            for (int it = 0; it < size; ++it) {
                image.push_back((buffer[it] == 0) ? 0 : 1);
            }

            // Instantiate the image as a tensor_3d and store it in a vector
            images.push_back(tensor_3d(nrows, ncols, 1, image));
        }

        delete[] buffer;
        return images;
    };

    // This method helps in loading labels to a std::vector<tensor_3d>.
    // It is a helper method which follows the description of the dataset by the authors.
    std::vector<int> dataset::load_labels_mnist_dataset(std::string &filename) const {
        std::ifstream label_file(filename, std::ios::binary);
        // Check if the label file could not be opened
        if (!label_file.is_open()) {
            std::cerr<<"Failed to open the label file."<<std::endl;
            return {};
        }

        std::vector<int> labels;

        int8_t size_of_int32 = sizeof(int32_t);
        char tmp[size_of_int32];

        // assert if label_file format is appropriate
        label_file.read(tmp, size_of_int32);
        int32_t magic_number = char4_to_int(tmp);

        if (magic_number != 0x801) {
            std::cerr<<"Magic number does not match the expected value 0x801."<<std::endl;
            return {};
        }
        (void) magic_number;

        // getting the number of labels
        label_file.read(tmp, size_of_int32);
        int32_t number_of_labels = char4_to_int(tmp);

        // Looping through all labels and store them as 8 bits int in a vector
        char tmp_value;
        for (int n = 0; n < number_of_labels; ++n) {
            label_file.read(&tmp_value, 1);
            labels.push_back(tmp_value);
        }

        return labels;
    }

    //This method helps display the image of the digit in the terminal without the need
    //to install other external packages.
    void dataset::show_image(tensor_3d &image) const {
        for (std::size_t y = 0; y < image.get_height(); ++y) {
            for (std::size_t x = 0; x < image.get_width(); ++x) {

                std::cout << ((image(y, x, 0) == 0) ? ' ' : '*');
            }
            std::cout << std::endl;
        }
    }

} // namespace
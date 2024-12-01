# Assignment 2 - Algorithms & Parallel Computing in C++ 2024  

This repository contains the implementation of **Assignment 2** for the Algorithms and Parallel Computing (APC) course in C++, November 2024. The assignment focuses on implementing key components of a **Convolutional Neural Network (CNN)** in C++, including layers such as convolutional, max pooling, and fully connected layers.  

## Project Structure  

- **`matrix` Class**: Provides matrix operations including initialization, dot product, and printing.
- **`tensor_3d` Class**: Handles 3D tensor manipulations, including element-wise operations and scaling.  
- **`feature_layer` Base Class**: Abstract class for feature extraction layers, including convolution and pooling.  
- **`cnn` Class**: Implements a simple CNN architecture for digit recognition using the LeNet model.  

## Key Features  

- **Class: Convolutional Layer**  
   - `tensor_3d evaluate(const tensor_3d& input)`  
     Performs the convolution of the input with the convolutional filter as described in Equation 4.  
   - `tensor_3d forward_pass(const tensor_3d& inputs)`  
     Performs a forward pass of the layer with the input. The output is obtained after applying the activation function to the result of the `evaluate` function.  

- **Class: Max Pooling Layer**  
   - `tensor_3d evaluate(const tensor_3d& input)`  
     Performs the max pooling operation on the input using the pooling filter as described in Equation 7.  
   - `tensor_3d forward_pass(const tensor_3d& inputs)`  
     Executes a forward pass of the layer with the input. The output is obtained after applying the activation function to the result of the `evaluate` function.  

- **Class: Fully Connected (FC) Layer**  
   - `std::vector<double> compute(const std::vector<double>& inputs)`  
     Computes the weighted sum of the inputs with the layer weights, returning the raw output (without activation). Implements Equation 1. For simplicity, the bias term \( b \) is set to 0.  
   - `std::vector<double> forward_pass(const std::vector<double>& inputs)`  
     Executes a forward pass through the layer by applying weights and the activation function to the input vector, returning the output vector.  

- **LeNet Architecture**  
   Processes MNIST-like images to recognize handwritten digits using convolutional, max pooling, and fully connected layers.

- **Remark : What is a forward pass ?**
   - A forward pass is feeding an input (like an image) through each layer of the network, starting from the first and moving sequentially to the last, to compute the final output.
   - In this project, we have to code the forward pass, specifically for each layer ! And then in the end there is a "full forward pass" that applies in the right order all the layer-specific forward passes !
   - Example for a CNN : for an image classification problem using a Convolutional Neural Network (CNN):
      - The image is passed through convolutional layers to detect features like edges or textures.
      - The feature maps are reduced using pooling layers to focus on significant patterns.
      - The processed data is passed to fully connected layers, which combine the features to make a prediction (e.g., assigning a label to the image). 

## Testing  

The repository includes seven predefined tests (`test1()` through `test7()`) in the `main.cpp` file.  
- Uncomment specific tests in `main()` to validate individual components.  
- Tests are incremental; ensure all dependencies are resolved before proceeding to higher tests.    

For additional details, refer to the **Assignment2_2024.pdf** document in the repository.  

## References  

- LeCun, Y., Bottou, L., Bengio, Y., & Haffner, P. (1998). Gradient-based learning applied to document recognition. Proceedings of the IEEE, 86(11), 2278–2324.  

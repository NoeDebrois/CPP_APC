# Assignment 2 - Algorithms & Parallel Computing in C++ 2024  

This repository contains the implementation of **Assignment 2** for the Advanced Programming Concepts (APC) course, November 2024. The assignment focuses on implementing key components of a **Convolutional Neural Network (CNN)** in C++, including layers such as convolutional, max pooling, and fully connected layers.  

## Project Structure  

- **`matrix` Class**: Provides matrix operations including initialization, dot product, and printing.
- **`tensor_3d` Class**: Handles 3D tensor manipulations, including element-wise operations and scaling.  
- **`feature_layer` Base Class**: Abstract class for feature extraction layers, including convolution and pooling.  
- **`cnn` Class**: Implements a simple CNN architecture for digit recognition using the LeNet model.  

## Key Features  

- **Class: convolutional layer**
   – tensor 3d evaluate(const tensor 3d& input) : Method that performs the convolution of the input with the convo- lutional filter as described in Equation 4.
   – tensor 3d forward pass(const tensor 3d& inputs) Method that performs a forward pass of the layer to the input. The output is obtained after applying the activation to the result of the evaluate function.
- **Max Pooling Layers**: Performs spatial dimension reduction with pooling filters.  
- **Fully Connected Layers**: Handles dense connections and activations for classification.  
- **LeNet Architecture**: Processes MNIST-like images to recognize handwritten digits.  

## Testing  

The repository includes seven predefined tests (`test1()` through `test7()`) in the `main.cpp` file.  
- Uncomment specific tests in `main()` to validate individual components.  
- Tests are incremental; ensure all dependencies are resolved before proceeding to higher tests.  

## How to Run  

1. Clone the repository:  
   ```bash  
   git clone <repo-url>  
   cd <repo-name>  
   ```  

2. Compile the project using your preferred C++ compiler:  
   ```bash  
   g++ -o Assignment2 main.cpp -std=c++17  
   ```  

3. Run the compiled program:  
   ```bash  
   ./Assignment2  
   ```  

4. Ensure output matches expected results for all test cases.  

For additional details, refer to the **Assignment2_2024.pdf** document in the repository.  

## References  

- LeCun, Y., Bottou, L., Bengio, Y., & Haffner, P. (1998). Gradient-based learning applied to document recognition. Proceedings of the IEEE, 86(11), 2278–2324.  
